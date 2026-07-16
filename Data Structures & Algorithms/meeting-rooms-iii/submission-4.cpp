class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return (long long)a[0] < (long long)b[0];
        });
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        vector<int> count(n);

        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            while (!used.empty() && used.top().first <= start) {
                int room = used.top().second;
                used.pop();
                available.push(room);
            }
            if (available.empty()) {
                auto current = used.top();
                used.pop();
                end = current.first + (end - start);
                available.push(current.second);
            }

            int room = available.top();
            available.pop();
            used.push({end, room});
            count[room]++;
        }

        int maxRoom = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
    }
};