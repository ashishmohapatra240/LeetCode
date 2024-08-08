class Solution {
public:
    int dp[1001];
    int help(int N) {
        if (N == 1)
            return 0;
        if (dp[N] != -1)
            return dp[N];
        else {
            for (int i = 1; i < N; i++) {
                if (N % i == 0) {
                    if (help(N - i) == 0)
                        return dp[N] = 1;
                }
            }

            return 0;
        }
    }
    bool divisorGame(int n) {
        memset(dp, -1, sizeof(dp));
        return help(n);
    }
};