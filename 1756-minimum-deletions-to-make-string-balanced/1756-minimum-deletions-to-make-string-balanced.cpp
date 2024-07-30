class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int count_b = 0;
        int min_deletions = 0;
        
        for (char c : s) {
            if (c == 'b') {
                count_b++;
            } else {
                min_deletions = min(min_deletions + 1, count_b);
            }
        }
        
        return min_deletions;
    }
};
