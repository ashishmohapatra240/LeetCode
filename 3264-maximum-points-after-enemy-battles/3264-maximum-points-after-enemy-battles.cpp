class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int minEnergy =enemyEnergies[0];
        if(minEnergy>currentEnergy) return 0;
        long long points = 0;

        for(auto energy: enemyEnergies)
        points+=energy;
        points-=minEnergy;
        points+=currentEnergy;

        return points/minEnergy;
        
    }
};