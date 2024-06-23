class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), i = 0, j = 0, maxLen = 0;

        multiset<int> s;
        while (j < n) {
            s.insert(nums[j]);
            int diff = *s.rbegin() - *s.begin();
            while (i < j && diff > limit) {
                auto it = s.find(nums[i]);
                s.erase(it);
                i++;
                diff = *s.rbegin() - *s.begin();
            }
            maxLen = max(maxLen, (int)s.size());
            j++;
        }
        return maxLen;
    }
};