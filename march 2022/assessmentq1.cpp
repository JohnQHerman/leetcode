// Given an integer array ""nums", find three numbers whose product is maximum and return the maximum product.

// Constraints:
// 3 <= nums.length <= 10^4
// -1000 <= nums[i] <= 1000

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int a = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int b = nums[0] * nums[1] * nums[n - 1];
        return max(a, b);
    }
};