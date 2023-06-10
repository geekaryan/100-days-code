// 1802. Maximum Value at a Given Index in a Bounded Array
// You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

// nums.length == n
// nums[i] is a positive integer where 0 <= i < n.
// abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
// The sum of all the elements of nums does not exceed maxSum.
// nums[index] is maximized.
// Return nums[index] of the constructed array.

// Note that abs(x) equals x if x >= 0, and -x otherwise.

class Solution
{
public:
    bool isValid(long long mid, int n, int index, int maxSum)
    {
        long long sum = (mid * (mid + 1)) / 2;
        sum += sum;
        sum -= mid;
        long long left = mid - (index + 1);
        if (left < 0)
        {
            sum += -left;
        }
        else
        {
            sum -= (left * (left + 1)) / 2;
        }
        long long right = mid - (n - index);
        if (right < 0)
        {
            sum += -right;
        }
        else
        {
            sum -= (right * (right + 1)) / 2;
        }
        return sum <= maxSum;
    }
    int maxValue(int n, int index, int maxSum)
    {

        long long l = 1;
        long long r = 1e9;
        int res = -1;

        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (isValid(mid, n, index, maxSum))
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
};