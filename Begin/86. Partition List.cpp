// https://leetcode.com/problems/partition-list/

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
    ListNode *partition(ListNode *head, int x)
    {
        // 小于x部分
        ListNode _head_1 = ListNode(); // 空的头节点
        ListNode *head_1 = &_head_1;
        // 大于等于x部分
        ListNode _head_2 = ListNode(); // 空的头节点
        ListNode *head_2 = &_head_2;
        for (ListNode *node = head; node != nullptr; node = node->next)
        {
            if (node->val < x)
            {
                head_1->next = node;
                head_1 = head_1->next;
            }
            else
            {
                head_2->next = node;
                head_2 = head_2->next;
            }
        }
        head_1->next = _head_2.next; // 拼接起来
        head_2->next = nullptr;      // 尾结点指向空
        return _head_1.next;
    }
};