class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);

        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        sort(cars.begin(), cars.end(),
             [](const pair<int, double>& a, const pair<int, double>& b) {
                 return a.first > b.first;
             });
        int count = 0;
        double prevTime = 0;

        for (auto& car : cars) {
            if (car.second > prevTime) {
                count++;
                prevTime = car.second;
            }
        }

        return count;
    }
};