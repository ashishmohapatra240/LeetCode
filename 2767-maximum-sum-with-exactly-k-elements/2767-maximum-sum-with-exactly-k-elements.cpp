class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        int sum = 0;
        while (k) {
            sum += maxi;
            maxi = maxi + 1;
            k--;
        }
        return sum;
    }
};