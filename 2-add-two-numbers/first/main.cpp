#include <iostream>
#include <queue>

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
        ListNode anser = ListNode();
        queue<int> nums;
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        bool isAdvanced = false;

        while (true)
        {
            if (node1 == nullptr && node2 == nullptr)
            {
                break;
            }

            int added = 0;
            if (node1 != nullptr)
            {
                added += node1->val;
                node1 = node1->next;
            }
            if (node2 != nullptr)
            {
                added += node2->val;
                node2 = node2->next;
            }

            if (isAdvanced)
            {
                added += 1;
                isAdvanced = false;
            }
            if (added > 9)
            {
                added = added - 10;
                isAdvanced = true;
            }
            nums.push(added);
        }
        if (isAdvanced)
        {
            nums.push(1);
        }

        ListNode *firstNode = new ListNode(nums.front());
        ListNode *answer = firstNode;
        ListNode *current = firstNode;
        nums.pop();
        while (nums.size() > 0)
        {
            ListNode *newNode = new ListNode(nums.front());
            current->next = newNode;
            current = newNode;
            nums.pop();
        }

        return answer;
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