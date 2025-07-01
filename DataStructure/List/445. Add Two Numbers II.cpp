// https://leetcode.com/problems/add-two-numbers-ii/

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
        // 结点入栈
        stack<ListNode *> s1, s2;
        while (l1)
        {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2);
            l2 = l2->next;
        }
        // 反向出栈，将正序链表变为逆序链表
        ListNode *head1 = new ListNode();
        ListNode *dummy_head1 = head1;
        while (!s1.empty())
        {
            head1->next = s1.top();
            head1 = head1->next;
            s1.pop();
        }
        head1->next = nullptr;     // 断开之前的连接，避免成环
        head1 = dummy_head1->next; // 定位到链表头

        ListNode *head2 = new ListNode();
        ListNode *dummy_head2 = head2;
        while (!s2.empty())
        {
            head2->next = s2.top();
            head2 = head2->next;
            s2.pop();
        }
        head2->next = nullptr;     // 断开之前的连接，避免成环
        head2 = dummy_head2->next; // 定位到链表头

        // 计算和
        ListNode *head = new ListNode();
        int num1 = 0, num2 = 0, sum = 0, flow = 0;
        while (head1 || head2 || flow)
        { // 两条链表走完且没有进位时才能结束循环
            if (head1)
            {
                num1 = head1->val;
                head1 = head1->next;
            }
            else
                num1 = 0;
            if (head2)
            {
                num2 = head2->val;
                head2 = head2->next;
            }
            else
                num2 = 0;

            sum = (num1 + num2 + flow) % 10;
            flow = int((num1 + num2 + flow) / 10);

            // 在链表头部插入，形成正序链表
            ListNode *new_node = new ListNode(sum);
            new_node->next = head->next;
            head->next = new_node;
        }
        return head->next;
    }
};