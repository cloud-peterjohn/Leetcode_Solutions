// https://leetcode.com/problems/middle-of-the-linked-list/description/

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while ((fast->next != nullptr) && (fast->next->next != nullptr))
        {
            // 慢指针走一步，快指针走两步
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast->next == nullptr)
            return slow; // 奇数个结点，只有一个中点
        else
            return slow->next; // 偶数个结点，返回后一个中点
    }
};