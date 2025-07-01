// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode *head)
    {
        // 只有一个结点，一定是回文串
        if (head->next == nullptr)
            return true;

        // 从中点将链表分为结点数量相同的两部分
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != nullptr)
            slow = slow->next; // 对于奇数个结点，从中间点移动至右半部分首结点

        // 断为两部分，并将右半部分结点逆序
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        ListNode *next = slow->next;
        while (curr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }

        // 判断回文：从head开始遍历和从prev开始遍历的每个结点都相同，直至prev指向NULL为止
        while (prev)
        {
            if (head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
