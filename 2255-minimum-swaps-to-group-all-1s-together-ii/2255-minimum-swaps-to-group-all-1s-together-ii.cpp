class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total_ones = 0;

        for (int num : nums) {
            if (num == 1) {
                total_ones++;
            }
        }

        if (total_ones == 0 || total_ones == n) {
            return 0;
        }

  
        int current_zeros = 0, min_zeros = INT_MAX;
        for (int i = 0; i < 2 * n; ++i) {
            if (i < total_ones) {
                if (nums[i % n] == 0)
                    current_zeros++;
            } else {
                if (nums[i % n] == 0)
                    current_zeros++;
                if (nums[(i - total_ones) % n] == 0)
                    current_zeros--;
            }

            if (i >= total_ones - 1) {
                min_zeros = min(min_zeros, current_zeros);
            }
        }

        return min_zeros;
    }
};
