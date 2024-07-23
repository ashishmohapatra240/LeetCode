class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    }

    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> A(mp.begin(), mp.end());
        sort(A.begin(), A.end(), cmp);

        for (auto& p : A) {
            for (int i = 0; i < p.second; ++i) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
