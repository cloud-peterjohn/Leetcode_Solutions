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