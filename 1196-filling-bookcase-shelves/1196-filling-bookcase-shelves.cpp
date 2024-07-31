class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            int current_width = 0, max_height = 0;
            
            for (int j = i; j > 0; --j) {
                current_width += books[j - 1][0];
                
                if (current_width > shelfWidth) break;
                
                max_height = max(max_height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + max_height);
            }
        }
        
        return dp[n];
    }
};
