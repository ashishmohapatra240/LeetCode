class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int current_sum = 0;
            for (int j = i; j < nums.size(); j++) {
                current_sum += nums[j];
                if (current_sum == k)
                    count++;
            }
        }
        return count;
    }
};
