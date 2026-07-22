class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt=0;
        for(int i:s)
            if(i=='1')
                cnt++;

        s = '1'+s+'1';
        int ans=cnt,i=0,n=s.length();
        while(i<n && s[i]=='1')
            i++;

        int c10=0;
        while(i<n && s[i]=='0'){
            i++;
            c10++;
        }

        while(i<n){

            int c11=0;
            while(i<n && s[i]=='1'){
                c11++;
                i++;
            }

            if(c11==0)
                break;

            int c20=0;
            while(i<n && s[i]=='0'){
                i++;
                c20++;
            }

            if(c20==0)
                break;

            ans = max(ans,cnt+c10+c20);
            c10=c20;
        }
        return ans;
    }
};