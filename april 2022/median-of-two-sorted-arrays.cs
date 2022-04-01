// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Constraints:
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -10^6 <= nums1[i], nums2[i] <= 10^6

public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.Length;
        int n = nums2.Length;
        int[] merged = new int[m + n];
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                merged[k] = nums1[i];
                i++;
            }
            else
            {
                merged[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m)
        {
            merged[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n)
        {
            merged[k] = nums2[j];
            j++;
            k++;
        }
        if ((m + n) % 2 == 0)
        {
            return (merged[(m + n) / 2] + merged[(m + n) / 2 - 1]) / 2.0;
        }
        else
        {
            return merged[(m + n) / 2];
        }
    }
}