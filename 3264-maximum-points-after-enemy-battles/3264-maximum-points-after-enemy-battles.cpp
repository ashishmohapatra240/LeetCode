class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int minEnergy = enemyEnergies[0];
        if (minEnergy > currentEnergy)
            return 0;
        long long sum = 0;

        for (auto energy : enemyEnergies)
            sum += energy;
        sum -= minEnergy;
        sum += currentEnergy;

        return sum / minEnergy;
    }
};