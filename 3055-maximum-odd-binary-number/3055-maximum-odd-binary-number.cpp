class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            ans.push_back('0');
        }
        for (auto c : s) {
            if (c == '1')
                count++;
        }
        if (count >= 1) {
            ans[s.size() - 1] = '1';
            count--;
        }
        int i = 0;
        while (count) {
            ans[i] = '1';
            i++;
            count--;
        }
        return ans;
    }
};