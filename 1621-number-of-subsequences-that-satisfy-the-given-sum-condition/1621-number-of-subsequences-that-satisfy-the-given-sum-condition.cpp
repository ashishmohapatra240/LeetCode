#define mod 1000000007

class Solution {
public:
    long help(long x, long y) {
        long ans = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            y /= 2;
        }
        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            if (nums[s] + nums[e] <= target) {
                ans = (ans + help(2, e - s)) % mod;
                s++;
            } else {
                e--;
            }
        }

        return ans;
    }
};
