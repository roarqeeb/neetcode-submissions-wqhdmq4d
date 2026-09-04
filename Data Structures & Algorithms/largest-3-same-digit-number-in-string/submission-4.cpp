class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        int val = 0;

        for (int i = 0; i < num.length() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string tmp = num.substr(i, 3);
                if (val <= stoi(tmp)) {
                    val = stoi(tmp);
                    res = tmp;
                }
            }
        }

        return res;
    }
};