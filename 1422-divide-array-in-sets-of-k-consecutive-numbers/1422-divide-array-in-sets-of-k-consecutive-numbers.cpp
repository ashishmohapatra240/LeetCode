class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
            if (nums.size() % k != 0)
            return false;
        map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        for (auto [num, freq] : mp) {
            while (freq--) {
                for (int cur = num; cur < num + k; cur++) {
                    if (mp[cur] == 0)
                        return false;
                    mp[cur]--;
                }
            }
        }
        return true;
    }
};