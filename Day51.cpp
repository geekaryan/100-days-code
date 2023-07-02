// 2517. Maximum Tastiness of Candy Basket
// You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.

// The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute difference of the prices of any two candies in the basket.

// Return the maximum tastiness of a candy basket.

class Solution
{
public:
    int maximumTastiness(vector<int> &price, int k)
    {

        sort(price.begin(), price.end());

        int n = price.size();
        vector<int> gap;
        for (int i = 1; i < n; i++)
        {
            gap.push_back(abs(price[i] - price[i - 1]));
        }

        int start = 0;
        int end = price[n - 1] - price[0];

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int curr = 0;
            int count = 0;
            for (auto i : gap)
            {
                curr += i;
                if (curr >= mid)
                {
                    curr = 0;
                    count++;
                }
            }
            if (count >= (k - 1))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return end;
    }
};