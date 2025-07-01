// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int num1 = 0, num2 = 0, sum = 0, overflow = 0;
        ListNode *head = new ListNode();
        ListNode *dummy_head = head;
        // 共同部分
        while (l1 && l2)
        {
            num1 = l1->val;
            num2 = l2->val;
            sum = (num1 + num2 + overflow) % 10;
            overflow = int((num1 + num2 + overflow) / 10);

            head->next = new ListNode(sum);
            head = head->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        // 多出来的高位部分
        while (l1)
        {
            num1 = l1->val;
            sum = (num1 + overflow) % 10;
            overflow = int((num1 + overflow) / 10);

            head->next = new ListNode(sum);
            head = head->next;

            l1 = l1->next;
        }
        while (l2)
        {
            num2 = l2->val;
            sum = (num2 + overflow) % 10;
            overflow = int((num2 + overflow) / 10);

            head->next = new ListNode(sum);
            head = head->next;

            l2 = l2->next;
        }
        // 最终如果有进位
        if (overflow)
        {
            head->next = new ListNode(overflow);
            head = head->next;
        }
        return dummy_head->next;
    }
};