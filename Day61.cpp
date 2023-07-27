// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

class Solution
{
public:
    bool isValid(string s)
    {

        vector<char> ans;

        for (auto x : s)
        {
            ans.push_back(x);
        }

        int count = 0;
        vector<char> check;
        check.push_back(ans[0]);
        for (int i = 1; i < ans.size(); i++)
        {
            if (!check.empty() &&
                ((check.back() == '(' && ans[i] == ')') ||
                 (check.back() == '{' && ans[i] == '}') ||
                 (check.back() == '[' && ans[i] == ']')))
            {
                check.pop_back();
                count++;
            }
            else
            {
                check.push_back(ans[i]);
            }
        }

        cout << count << endl;

        if (check.empty())
        {
            return true;
        }

        return false;
    }
};