class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) {
                return true;
            }
        }
        
        return bouquets >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (static_cast<long long>(m) * k > n) return -1; 
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};
