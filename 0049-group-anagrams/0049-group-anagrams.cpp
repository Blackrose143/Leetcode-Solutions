class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> s2=strs;
        int n = strs.size();
        for(string& s:s2){
            sort(s.begin(),s.end());
        }
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<n;i++) {
            string s = s2[i];
            mp[s].push_back(i);
        }
        vector<vector<string>> ans(mp.size());
        int i=0;
        for(auto pi:mp) {
            vector<int> vc=pi.second;
            for(int idx:vc)
                ans[i].push_back(strs[idx]);
            i++;
        }
        return ans;
    }
};