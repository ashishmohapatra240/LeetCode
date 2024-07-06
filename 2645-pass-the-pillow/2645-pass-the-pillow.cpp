class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2 * (n - 1);
        int rem = time % cycle;
        if (rem < n)
            return rem + 1;
        else {
            return 2 * n - 1 - rem;
        }
    }
};