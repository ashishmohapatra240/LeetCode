class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < score.size(); ++i) {
            pq.push({score[i], i});
        }
        vector<string> answer(score.size());
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int rank = 0;
        while (!pq.empty()) {
            auto [score, index] = pq.top();
            pq.pop();
            if (rank < 3) {
                answer[index] = medals[rank];
            } else {
                answer[index] = to_string(rank + 1);
            }
            ++rank;
        }
        return answer;
    }
};