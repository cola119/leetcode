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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return nullptr;
        if (!head->next->next)
            return nullptr;
        ListNode *tortoise = head->next;
        ListNode *hare = head->next->next;
        while (tortoise != hare)
        {
            if (!tortoise || !hare || !tortoise->next || !hare->next)
                return nullptr;
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        tortoise = head;
        while (tortoise != hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return tortoise;
    }
};