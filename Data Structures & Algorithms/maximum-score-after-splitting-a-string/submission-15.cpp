class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), res = 0;
        for (int i = 1; i < n; i++) {
            int leftZero = 0, rightOne = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == '0') {
                    leftZero++;
                }
            }
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    rightOne++;
                }
            }
            res = max(res, leftZero + rightOne);
        }
        return res;
    }
};