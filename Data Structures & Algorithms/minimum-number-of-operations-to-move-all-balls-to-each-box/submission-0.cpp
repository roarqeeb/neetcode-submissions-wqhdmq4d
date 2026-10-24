class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);

        for (int pos = 0; pos < n; pos++) {
            for (int i = 0; i < n; i++) {
                if (boxes[i] == '1') {
                    res[pos] += abs(pos - i);
                }
            }
        }

        return res;
    }
};