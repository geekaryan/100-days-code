// 347. Top K Frequent Elements
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
class Solution
{
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        vector<pair<int, int>> freq;

        unordered_map<int, int> m;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        for (auto x : m)
        {
            freq.push_back({x.first, x.second});
        }

        sort(freq.begin(), freq.end(), compare);

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};