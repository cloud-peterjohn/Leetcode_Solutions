// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = new ListNode();
        ListNode *p_head = p;
        int prev_val = -999;
        while (head)
        {
            if ((head->val != prev_val && head->next && head->val != head->next->val) || (head->val != prev_val && !head->next))
            {
                p->next = head;
                p = p->next;
            }
            prev_val = head->val;
            head = head->next;
        }
        p->next = nullptr; // 断开与原链表中的连接
        return p_head->next;
    }
};