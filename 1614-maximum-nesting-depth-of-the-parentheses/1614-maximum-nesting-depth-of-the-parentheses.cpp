class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,ans=0;
        for(char c:s) {
            if(c=='(')
                cnt++;
            if(c==')')
                cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};