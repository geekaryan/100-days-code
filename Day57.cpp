// 260. Single Number III
//     Given an integer array nums,
//     in which exactly two elements appear only once and all the other elements appear exactly twice.Find the two elements that appear only once.You can return the answer in any order.

//         You must write an algorithm that runs in linear runtime complexity and
//         uses only constant extra space.

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> ans;

        map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (m[nums[i]] == 1)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};