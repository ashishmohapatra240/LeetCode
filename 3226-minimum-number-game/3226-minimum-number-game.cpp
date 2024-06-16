class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> arr;
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            arr.push_back(nums[2 * i + 1]);
            arr.push_back(nums[2 * i]);
        }
        return arr;
    }
};