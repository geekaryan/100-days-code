// 169. Majority Element
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the arr

class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> p;

        for (auto it : mp)
        {
            p.push_back({it.first, it.second});
        }

        sort(p.begin(), p.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < p.size(); i++)
        {
            ans.push_back(p[i].first);
        }

        return ans[0];
    }
};