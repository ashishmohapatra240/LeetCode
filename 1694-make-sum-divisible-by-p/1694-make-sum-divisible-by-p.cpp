class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        int n = nums.size();
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        
        if (total_sum % p == 0) return 0;

        int remainder = total_sum % p;
        std::unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;
        int prefix_sum = 0;
        int min_length = INT_MAX;

        for (int i = 0; i < n; ++i) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int target = (prefix_sum - remainder + p) % p;
            if (prefix_map.find(target) != prefix_map.end()) {
                min_length = min(min_length, i - prefix_map[target]);
            }
            prefix_map[prefix_sum] = i;
        }

        return min_length == INT_MAX || min_length == n ? -1 : min_length;
    }
};