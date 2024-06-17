class Solution {
public:
    int scoreOfString(std::string s) {
        int score = 0;
        for (size_t i = 1; i < s.length(); ++i) {
            score += std::abs(s[i] - s[i - 1]);
        }
        return score;
    }
};