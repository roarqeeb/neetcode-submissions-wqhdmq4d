class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        cache = unordered_map<int, vector<string>>();
        return backtrack(s, 0);
    }

private:
    unordered_set<string> wordSet;
    unordered_map<int, vector<string>> cache;

    vector<string> backtrack(const string& s, int i) {
        if (i == s.size())
            return {""};
        if (cache.count(i))
            return cache[i];

        vector<string> res;
        for (int j = i; j < s.size(); ++j) {
            string w = s.substr(i, j - i + 1);
            if (!wordSet.count(w))
                continue;
            vector<string> strings = backtrack(s, j + 1);
            for (const string& substr : strings) {
                string sentence = w;
                if (!substr.empty())
                    sentence += " " + substr;
                res.push_back(sentence);
            }
        }
        cache[i] = res;
        return res;
    }
};