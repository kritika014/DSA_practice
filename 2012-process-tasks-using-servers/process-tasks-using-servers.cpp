class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            freeservers;

        for (int i = 0; i < n; i++) {
            freeservers.push({servers[i], i});
        }

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            busyservers;

        vector<int> ans(m);
        long long currentTime = 0;

        for (int j = 0; j < m; j++) {
            currentTime = max(currentTime,(long long)j);

            while (!busyservers.empty() &&
                   get<0>(busyservers.top()) <= currentTime) {
                auto [freeTime, weight, index] = busyservers.top();
                busyservers.pop();
                freeservers.push({weight, index});
            }

            if (freeservers.empty()) {
                currentTime = get<0>(busyservers.top());

                while (!busyservers.empty() &&
                       get<0>(busyservers.top()) <= currentTime) {
                    auto [freeTime, weight, index] = busyservers.top();
                    busyservers.pop();
                    freeservers.push({weight, index});
                }
            }

            auto [serverw, serverIndex] = freeservers.top();
            freeservers.pop();

            ans[j] = serverIndex;

            long long finishTime = currentTime +  1LL *tasks[j];
            busyservers.push({finishTime, serverw, serverIndex});
        }

        return ans;
    }
};