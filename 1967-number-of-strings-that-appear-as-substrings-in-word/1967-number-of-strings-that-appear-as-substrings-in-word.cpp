class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> mp;
        int n=word.size(),ans=0;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=i;j<n;j++){
                s+=word[j];
                mp[s]++;
            }
        }
        for(string s:patterns){
            if(mp.find(s)!=mp.end())
                ans++;
        }
        return ans;
    }
};