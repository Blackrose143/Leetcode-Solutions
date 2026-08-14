class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=-1,n=s.length(),ans=0;
        unordered_map<char,int> mp;
        for(;i<n;i++) {
            while(j+1<n) {
                if(mp[s[j+1]]+1>2)
                    break;
                mp[s[j+1]]++;
                j++;
            }
            ans = max(ans, j-i+1);
            mp[s[i]]--;
        }
        return ans;
    }
};