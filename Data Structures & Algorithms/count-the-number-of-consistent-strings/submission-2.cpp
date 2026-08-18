class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;

        for (string& w : words) {
            bool flag = true;
            for (char c : w) {
                if (allowed.find(c) == string::npos) {
                    flag = false;
                    break;
                }
            }
            res += flag;
        }

        return res;
    }
};