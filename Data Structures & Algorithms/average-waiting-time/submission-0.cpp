class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long t = 0, total = 0;

        for (auto& c : customers) {
            int arrival = c[0], order = c[1];
            if (t > arrival) {
                total += t - arrival;
            } else {
                t = arrival;
            }
            total += order;
            t += order;
        }

        return (double) total / customers.size();
    }
};