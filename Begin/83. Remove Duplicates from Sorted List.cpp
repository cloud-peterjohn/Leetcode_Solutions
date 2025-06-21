// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
        if (head == nullptr)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr)
        { // 快指针进行遍历
            if (slow->val != fast->val)
            {
                slow->next = fast;
                slow = slow->next; // 慢指针维护去重后链表尾结点
                fast = fast->next;
            }
            else
            {
                fast = fast->next;
            }
        }
        slow->next = nullptr; // 断开与后面重复元素的连接
        return head;
    }
};