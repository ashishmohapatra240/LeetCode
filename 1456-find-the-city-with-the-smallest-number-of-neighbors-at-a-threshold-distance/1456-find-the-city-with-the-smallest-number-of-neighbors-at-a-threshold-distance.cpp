class Solution {
public:
    void dijkstra(int n, unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& result, int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        fill(result.begin(), result.end(), numeric_limits<int>::max());
        result[S] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int d = top.first;
            int node = top.second;

            if (adj.find(node) == adj.end()) continue;
            for (auto& p : adj[node]) {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, numeric_limits<int>::max()));

        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adj[start].emplace_back(end, weight);
            adj[end].emplace_back(start, weight);
        }

        for (int i = 0; i < n; i++) {
            vector<int> result(n);
            dijkstra(n, adj, result, i);
            for (int j = 0; j < n; j++) {
                shortestPathMatrix[i][j] = result[j];
            }
        }

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};