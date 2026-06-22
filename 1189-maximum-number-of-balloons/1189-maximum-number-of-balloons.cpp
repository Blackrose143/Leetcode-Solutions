class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;
        for(char c:text){
            if(c=='b' || c=='a' || c=='l' || c=='o' || c=='n')
                mp[c]++;
        }
        int ans=1e9;
        if(mp.size()<5)
            return 0;
        for(auto pi:mp){
            if(pi.first=='b' || pi.first=='a' || pi.first=='n'){
                ans=min(pi.second,ans);
            }else{
                ans=min(pi.second/2,ans);
            }
        }
        if(ans==1e9)
            return 0;
        return ans;
    }
};