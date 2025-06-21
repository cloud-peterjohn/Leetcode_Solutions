// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if ((list1 == nullptr) && (list2 != nullptr))
            return list2;
        if ((list1 != nullptr) && (list2 == nullptr))
            return list1;
        if ((list1 == nullptr) && (list2 == nullptr))
            return nullptr;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while ((list1 != nullptr) || (list2 != nullptr))
        {
            // 一个list已经合并完
            if (list1 == nullptr)
            {
                tail->next = list2;
                break;
            }
            else if (list2 == nullptr)
            {
                tail->next = list1;
                break;
            }
            // 两个list都还没合并完
            else
            {
                if (list1->val <= list2->val)
                {
                    ListNode *new_node = list1;
                    if (head == nullptr)
                    { // 首个结点时
                        head = new_node;
                        tail = new_node;
                    }
                    else
                    {
                        tail->next = new_node; // 加到链表末尾
                        tail = new_node;
                    }
                    list1 = list1->next;
                }
                else
                {
                    ListNode *new_node = list2;
                    if (head == nullptr)
                    { // 首个结点时
                        head = new_node;
                        tail = new_node;
                    }
                    else
                    {
                        tail->next = new_node; // 加到链表末尾
                        tail = new_node;
                    }
                    list2 = list2->next;
                }
            }
        }
        return head;
    }
};