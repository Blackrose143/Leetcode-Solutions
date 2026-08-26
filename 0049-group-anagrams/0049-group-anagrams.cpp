class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;

        for(string s:strs) {
            string cur=s;
            sort(s.begin(),s.end());
            mp[s].push_back(cur);
        }

        for(auto pi:mp)
            ans.push_back(pi.second);
        return ans;
    }
};