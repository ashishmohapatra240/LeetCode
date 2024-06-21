class Solution {
public:
    void reverseStringHelper(int i, vector<char>& s, int n) {
        if (i >= n / 2)
            return;
        swap(s[i], s[n - i - 1]);
        reverseStringHelper(i + 1, s, n);
    }
    void reverseString(vector<char>& s) {
        reverseStringHelper(0, s, s.size());
    }
};