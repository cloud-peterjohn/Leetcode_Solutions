// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

// naive solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> s;
        while (headA != nullptr)
        {
            s.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr)
        {
            if (s.find(headB) != s.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

// better solution with double pointers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while (p1 != p2)
        {
            // p1走一步，如果走到A链表末尾，转到B链表
            if (p1 != nullptr)
                p1 = p1->next;
            else
                p1 = headB;
            // p2走一步，如果走到B链表末尾，转到A链表
            if (p2 != nullptr)
                p2 = p2->next;
            else
                p2 = headA;
        }
        return p1; // 即使没有交点，末尾的nullptr也视作相同
    }
};