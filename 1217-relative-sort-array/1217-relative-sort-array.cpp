class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> result;
        vector<int> not_in_arr2;

        for (int num : arr1) {
            mp[num]++;
        }
        for (int num : arr2) {
            if (mp.find(num) != mp.end()) {
                for (int j = 0; j < mp[num]; j++) {
                    result.push_back(num);
                }
                mp.erase(num);
            }
        }

        for (auto& pair : mp) {
            for (int j = 0; j < pair.second; j++) {
                not_in_arr2.push_back(pair.first);
            }
        }
        sort(not_in_arr2.begin(), not_in_arr2.end());
        result.insert(result.end(), not_in_arr2.begin(), not_in_arr2.end());

        return result;
    }
};