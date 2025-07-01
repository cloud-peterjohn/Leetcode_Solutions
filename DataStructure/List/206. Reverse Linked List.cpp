// https://leetcode.com/problems/reverse-linked-list/description/

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

// 迭代解法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        stack<ListNode *> st;
        while (head)
        {
            st.push(head);
            head = head->next;
        }

        ListNode *result = new ListNode();
        ListNode *dummy_head = result;
        while (!st.empty())
        {
            ListNode *node = st.top();
            st.pop();
            result->next = node;
            result = result->next;
        }
        result->next = nullptr; // 断开冗余链接，避免成环
        return dummy_head->next;
    }
};

// 迭代解法且不使用额外存储空间
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;
        while (curr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }
        return prev;
    }
};

// 递归解法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *reversed = reverseList(head->next);
        head->next->next = head; // head->next实际是反转后的尾结点，head需要接在尾结点之后成为新的尾结点
        head->next = nullptr;    // 新尾结点（head）之后为NULL
        return reversed;         // 返回新链表头结点
    }
};