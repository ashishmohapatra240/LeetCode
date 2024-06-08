class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 0; i < n; i++) {
            prefSum = (prefSum + nums[i]) % k;
            if (mp.find(prefSum) != mp.end()) {
                if (i + 1 - mp[prefSum] >= 2)
                    return true;
            } else {
                mp[prefSum] = i + 1;
            }
        }
        return false;
    }
};