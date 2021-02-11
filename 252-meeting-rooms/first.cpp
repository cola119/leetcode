#include <vector>
#include <sort>
using namespace std;

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> const &lhs, vector<int> const &rhs) {
            return rhs[0] > lhs[0];
        });
        for (int i = 0; i < static_cast<int>(intervals.size()) - 1; i++)
        {
            vector<int> cur = intervals[i];
            vector<int> nex = intervals[i + 1];
            if (cur[1] > nex[0])
                return false;
        }
        return true;
    }
};