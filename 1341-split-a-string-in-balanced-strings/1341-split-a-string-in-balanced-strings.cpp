class Solution {
public:
    int balancedStringSplit(string s) {
        int lcounter = 0;
        int rcounter = 0;
        int counter = 0;
        for (auto c : s) {
            if (c == 'L')
                lcounter++;
            else
                rcounter++;
            if (lcounter == rcounter)
                counter++;
        }
        return counter;
    }
};