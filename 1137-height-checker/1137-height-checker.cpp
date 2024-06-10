class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        int count = 0;
        for (int height : heights) {
            expected.push_back(height);
        }
        sort(expected.begin(),expected.end());
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i])
                count++;
        }
        return count;
    }
};