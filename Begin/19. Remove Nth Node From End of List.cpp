// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i = 0; i < n - 1; i++)
            p1 = p1->next;
        ListNode *prev_node = nullptr;
        while (p1->next != nullptr)
        {
            p1 = p1->next;
            prev_node = p2;
            p2 = p2->next;
        }
        if (prev_node != nullptr)
        {
            cout << "prev " << prev_node->val;
            // 此时prev指向待删除结点的前驱结点,p2指向待删除结点
            ListNode *next_node = p2->next;
            // 删除目标结点
            prev_node->next = next_node;
            delete p2;
            return head;
        }
        else
        {
            // 待删除的是头结点
            ListNode *new_head = head->next;
            delete head;
            return new_head;
        }
    }
};