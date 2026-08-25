class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<char> mag(magazine.begin(), magazine.end());

        for (char c : ransomNote) {
            auto it = find(mag.begin(), mag.end(), c);
            if (it == mag.end()) return false;
            mag.erase(it);
        }

        return true;
    }
};