// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // 使用优先队列
#include <algorithm>
#include <vector>
#include <queue>
struct Compare
{ // 仿函数
    bool operator()(ListNode *n1, ListNode *n2)
    {
        return n1->val > n2->val; // 大于比较符反而是小顶堆
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode _head = ListNode();
        ListNode *head = &_head;
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

        // 将所有链表第一个结点放入小顶堆
        for (auto l : lists)
        {
            // 排除空结链表
            if (l != nullptr)
                pq.push(l);
        }
        while (!pq.empty())
        {
            // 取堆顶最小元素
            ListNode *node = pq.top();
            pq.pop();
            // 将最小元素放入新链表，并将旧链表的下一个结点放入优先队列
            head->next = node;
            head = head->next;
            if (node->next != nullptr)
                pq.push(node->next);
        }
        return _head.next;
    }
};

// 使用分治法
class Solution
{
private:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        ListNode *head = new ListNode();
        ListNode *dummy_head = head;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val < p2->val)
            {
                head->next = p1;
                head = head->next;
                p1 = p1->next;
            }
            else
            {
                head->next = p2;
                head = head->next;
                p2 = p2->next;
            }
        }
        if (p1 != nullptr)
            head->next = p1;
        if (p2 != nullptr)
            head->next = p2;
        return dummy_head->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists, int begin, int end)
    {
        if (begin == end)
            return lists[begin];
        int mid = (begin + end) / 2;
        ListNode *left = mergeKLists(lists, begin, mid);
        ListNode *right = mergeKLists(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};