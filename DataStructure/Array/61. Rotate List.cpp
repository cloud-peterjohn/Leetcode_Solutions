// https://leetcode.com/problems/rotate-list/description/

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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;

        // size of head
        int size = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            ++size;
        }

        // k
        if (size <= 1 || k == 0 || k == size)
            return head;
        k = k % size;

        // 连接成环
        tail->next = head;

        // 从新的头结点处断开
        for (int i = 0; i < size - k; ++i)
        {
            tail = tail->next;
        }
        ListNode *new_head = tail->next;
        tail->next = nullptr;
        return new_head;
    }
};