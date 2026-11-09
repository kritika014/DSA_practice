class Solution {
public:
    int find_max(vector<int> arr) {
        int ans = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] > ans) {
                ans = arr[i];
            }
        }
        return ans;
    }
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int m = arrival.size();
        vector<int> request_count(
            k, 0); // Fixed variable name from 'request' to 'request_count'

        // min_heap stores pairs of {free_time, server_id}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            busy_servers;

        // available servers tracked in a set (stores server IDs 0 to k-1)
        set<int> available_servers;
        for (int i = 0; i < k; ++i) {
            available_servers.insert(i);
        }

        for (int i = 0; i < m;
             i++) { // Fixed arrival.length() to arrival.size() (or m)
            long long curr = arrival[i]; // Use long long if needed, or int
                                         // matches load/arrival types
            int processing = load[i];

            // Free up servers that have completed their tasks by 'curr' time
            while (!busy_servers.empty() && busy_servers.top().first <= curr) {
                int finished_server = busy_servers.top().second;
                busy_servers.pop();
                available_servers.insert(
                    finished_server); // C++ set uses insert()
            }

            if (available_servers.empty()) {
                continue; // Drop request if no servers are free
            }

            int preferred = i % k;
            int assigned_server = -1;

            // Find the first available server ID >= preferred
            auto it = available_servers.lower_bound(preferred);

            if (it != available_servers.end()) {
                assigned_server = *it;
            } else {
                // Wrap around and take the smallest available server ID >= 0
                assigned_server = *available_servers.begin();
            }

            // Remove assigned server from the available set
            available_servers.erase(assigned_server);

            long long free_time = curr + processing;
            busy_servers.push({free_time, assigned_server});

            request_count[assigned_server]++;
        }

        int max_value = find_max(request_count);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (request_count[i] == max_value) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};