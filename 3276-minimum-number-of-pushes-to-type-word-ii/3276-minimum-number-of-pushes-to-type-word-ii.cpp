class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for (char ch : word) {
            freq[ch]++;
        }
        
        vector<int> frequencies;
        for (auto& entry : freq) {
            frequencies.push_back(entry.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());
        
        int totalPushes = 0;
        int pushCount = 1; 
        
        for (int i = 0; i < frequencies.size(); i++) {
            totalPushes += frequencies[i] * pushCount;
            if ((i + 1) % 8 == 0) {
                pushCount++;
            }
        }
        
        return totalPushes;
    }
};
