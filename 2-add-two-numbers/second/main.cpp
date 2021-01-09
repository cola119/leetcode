#include <iostream>

// LinkListの操作

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *first = new ListNode(0);
        ListNode *current = first;
        int s = 0;

        while (l1 != nullptr || l2 != nullptr || s == 1)
        {
            s = s + (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0);

            current->next = new ListNode();
            current = current->next;
            current->val = (s % 10);

            s = s / 10;

            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }

        return first->next;
    }
};

int main()
{
    Solution solver = Solution();

    ListNode *a1 = new ListNode(3);
    ListNode *b1 = new ListNode(4, a1);
    ListNode *a2 = new ListNode(4);

    ListNode *node1 = new ListNode(2, b1);
    ListNode *node2 = new ListNode(5, a2);

    ListNode *ans = solver.addTwoNumbers(node1, node2);

    cout << ans->val << endl;
    cout << ans->next->val << endl;
    cout << ans->next->next->val << endl;

    return 0;
}