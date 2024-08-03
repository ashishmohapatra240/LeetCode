class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> targetCount, arrCount;

        for (int num : target) {
            targetCount[num]++;
        }

         for (int num : arr) {
            arrCount[num]++;
        }

        return targetCount == arrCount;
    }
};