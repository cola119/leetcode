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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *suc = head->next;
        while (current && suc)
        {
            if (current->val != suc->val)
            {
                prev = current;
                current = current->next;
                suc = suc->next;
                continue;
            }
            while (suc && current->val == suc->val)
            {
                suc = suc->next;
            }

            if (prev != nullptr)
            {
                prev->next = suc;
                current = suc;
                suc = current ? current->next : current;
            }
            else
            {
                head = suc;
                current = head;
                suc = head ? head->next : head;
            }
        }
        return head;
    }
};