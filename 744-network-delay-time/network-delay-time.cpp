class Solution {
public:
    void solve(int src, vector<vector<pair<int, int>>>& adj, vector<int>&dist,
               int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Skip if a shorter path to u has already been processed
            if (d > dist[u])
                continue;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        int src = k;
        solve(src, adj, dist, n);

        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX)
                return -1; // Unreachable node found
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};