// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
private:
    ListNode *subsequent_nodes = nullptr;
    ListNode *reverseK(ListNode *head, int k)
    {
        // base case: 无需逆序
        if (k == 1)
        {
            subsequent_nodes = head->next;
            return head;
        }
        // 递归逆序前k-1个结点
        ListNode *reversed_head = reverseK(head->next, k - 1);
        // 将“当前结点、逆序的k-1个结点、尾部无需逆序的结点”拼接起来
        head->next->next = head;
        head->next = subsequent_nodes;
        return reversed_head;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 检查剩余结点是否足够K个
        ListNode *dummy_head = head;
        bool not_enough = false;
        for (int i = 0; i < k; ++i)
        {
            if (dummy_head == nullptr)
            {
                not_enough = true;
                break;
            }
            else
                dummy_head = dummy_head->next;
        }

        // base case: 不够K个结点，无需反转
        if (not_enough == true)
        {
            return head;
        }

        // 反转K个，剩余部分递归
        ListNode *reversed_head1 = reverseK(head, k);
        ListNode *reversed_head2 = reverseKGroup(dummy_head, k);
        // 将反转的前K个和处理后的剩余部分拼接起来(head为原来的头节点，现在是反转后前K个结点的最后一个)
        head->next = reversed_head2;
        return reversed_head1;
    }
};