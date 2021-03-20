class Solution
{
public:
    // N=emails.size(), M=max(email.length())
    // c O(NM) s O(N)
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> sent;
        for (auto email : emails)
        { //N
            // test.email+alex@leetcode.com
            string actual = "";
            bool hasPulse = false;
            int i = 0;
            // actual = testemail
            for (i = 0; i < email.length(); i++)
            { // @
                char str = email[i];
                if (str == '@')
                    break;
                if (hasPulse)
                    continue; //true
                if (str == '+')
                {
                    hasPulse = true;
                    continue;
                }
                if (str == '.')
                    continue;
                actual += str;
            }
            actual += email.substr(i);
            sent.insert(actual);
        }
        return sent.size();
    }
};