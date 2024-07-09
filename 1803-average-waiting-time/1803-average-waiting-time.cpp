class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int currentTime = 0;
        double totalWaitTime = 0;
        for (auto& customer : customers) {
            int arrivalTime = customer[0];
            int cookTime = customer[1];

            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }
            int waitTime = currentTime + cookTime - arrivalTime;
            totalWaitTime += waitTime;
            currentTime += cookTime;
        }
        return totalWaitTime/n;
    }
};