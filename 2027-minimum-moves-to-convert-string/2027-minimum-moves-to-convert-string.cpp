class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length(),cnt=0;
        for(int i=0;i<=n-3;i++) {
            if(s[i]=='X') {
                s[i]='0';
                s[i+1]='0';
                s[i+2]='0';
                cnt++;
            }
        }
        if(s[n-2]=='X' || s[n-1]=='X')
            cnt++;
        return cnt;   
    }
};