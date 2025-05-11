// https://leetcode.com/problems/linked-list-cycle-ii/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while ((fast->next != nullptr) && (fast->next->next != nullptr))
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break; // 第一次相遇
        }
        if ((fast->next == nullptr) || ((fast->next->next == nullptr)))
            return nullptr; // 没有环
        ListNode *new_node = head;
        while (new_node != slow)
        { // 第二次相遇
            new_node = new_node->next;
            slow = slow->next;
        }
        return slow;
    }
};