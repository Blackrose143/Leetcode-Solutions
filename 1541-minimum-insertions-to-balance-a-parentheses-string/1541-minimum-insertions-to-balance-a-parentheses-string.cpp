class Solution {
public:
    int minInsertions(string s) {
        int op=0,ans=0,n=s.length();
        for(int i=0;i<n;i++) {
            char c=s[i];
            if(c=='(')
                op++;
            else {
                if(i+1<n && s[i+1]==')')
                    i += 1;
                else
                    ans++;
                
                if(op>0)
                    op--;
                else
                    ans++;
            }
        }
        return ans+op*2;
    }
};