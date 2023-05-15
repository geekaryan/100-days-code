// 4. Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int j = 0;
        int k = -1;

        vector<int> nums3(m + n, 0);

        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                nums3[++k] = nums1[i++];
            }
            else
            {
                nums3[++k] = nums2[j++];
            }
        }

        while (i < m)
        {
            nums3[++k] = nums1[i++];
        }

        while (j < n)
        {
            nums3[++k] = nums2[j++];
        }

        int l = m + n;
        return l % 2 ? nums3[l / 2] : (nums3[l / 2] + nums3[l / 2 - 1]) / 2.0;
    }
};