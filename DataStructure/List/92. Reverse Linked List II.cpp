// https://leetcode.com/problems/reverse-linked-list-ii/description/

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

 // 迭代
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (right <= 1)
            return head; // 无需反转
        ListNode *prev = new ListNode(-9999);
        prev->next = head;
        ListNode *dummy_head = prev;
        ListNode *curr = head;
        ListNode *next = head->next;
        // 使得curr指向left结点（待反转的第一个节点）
        int i = 1;
        for (; i < left; ++i)
        {
            prev = curr;
            curr = next;
            next = curr->next;
        }
        // 反转
        ListNode *left_node = prev;
        for (; i <= right; ++i)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr)
                next = curr->next;
        }
        left_node->next->next = curr; // 右边剩余部分接回去
        left_node->next = prev;       // 左边剩余部分接回去
        return dummy_head->next;      // 返回头节点
    }
};

// 递归
class Solution
{
    ListNode *subsequent_nodes = nullptr; // 尾部无需逆序的结点
    ListNode *reverseN(ListNode *head, int n)
    {
        // base case
        if (n == 1)
        {
            subsequent_nodes = head->next;
            return head;
        }
        // 递归
        ListNode *reversed_head = reverseN(head->next, n - 1);
        head->next->next = head;       // 连接上前部无需逆序的结点
        head->next = subsequent_nodes; // 连接上尾部无需逆序的结点
        return reversed_head;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == 1)
            return reverseN(head, right - left + 1);                               // base case
        ListNode *reversed_head = reverseBetween(head->next, left - 1, right - 1); // head右边部分的头节点
        head->next = reversed_head;                                                // 将head与右边相连
        return head;
    }
};