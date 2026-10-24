class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> departures;for(auto& path:paths)departures.insert(path[0]);for(auto&path:paths)if(!departures.count(path[1]))return path[1];return "";
}
};
