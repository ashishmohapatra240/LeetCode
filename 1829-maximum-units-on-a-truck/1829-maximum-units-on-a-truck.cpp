class Solution {
public:
    static bool cmp(vector<int>& val1, vector<int>& val2) {
        return (val1[1] > val2[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int res = 0;
        for (auto boxType : boxTypes) {
            int numBoxes=min(truckSize, boxType[0]);
            res+=numBoxes*boxType[1];
            truckSize-=numBoxes;

            if(truckSize==0) break;
        }
        return res;
    }
};