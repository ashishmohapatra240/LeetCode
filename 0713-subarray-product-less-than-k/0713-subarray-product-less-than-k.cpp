class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            for (int j = i; j < n; j++) {
                if (prod * nums[j] > INT_MAX) break;
                prod *= nums[j];
                if (prod < k)
                    count++;
            }
        }
        return count;
    }
};