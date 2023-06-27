// 2748. Number of Beautiful Pairs

// You are given a 0-indexed integer array nums. A pair of indices i, j where 0 <= i < j < nums.length is called beautiful if the first digit of nums[i] and the last digit of nums[j] are coprime.

// Return the total number of beautiful pairs in nums.

// Two integers x and y are coprime if there is no integer greater than 1 that divides both of them. In other words, x and y are coprime if gcd(x, y) == 1, where gcd(x, y) is the greatest common divisor of x and y.

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            return gcd(b, a % b);
        }
    }
    int countBeautifulPairs(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int last = 0;
        int first = 0;
        for (int i = 0; i < n; i++)
        {
            int first_digit = to_string(nums[i])[0] - '0';
            for (int j = i + 1; j < n; j++)
            {
                int last_digit = to_string(nums[j])[to_string(nums[j]).length() - 1] - '0';
                if (gcd(first_digit, last_digit) == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};