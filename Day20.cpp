// 2418. Sort the People
// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

// For each index i, names[i] and heights[i] denote the name and height of the ith person.

// Return names sorted in descending order by the people's heights.
class Solution
{
public:
    static bool comp(pair<string, int> &a, pair<string, int> &b)
    {
        return a.second > b.second;
    }

    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {

        int n = names.size();

        vector<pair<string, int>> pairt;

        for (int i = 0; i < n; i++)
        {
            pairt.push_back({names[i], heights[i]});
        }

        sort(pairt.begin(), pairt.end(), comp);

        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(pairt[i].first);
        }

        return ans;
    }
};