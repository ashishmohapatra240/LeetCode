class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequency;
        for (const string& str : arr) {
            frequency[str]++;
        }
        int distinctCount = 0;
        for (const string& str : arr) {
            if (frequency[str] == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return str;
                }
            }
        }
        return "";
    }
};