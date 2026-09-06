class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length() , ans = 0;
        for(int i=1;i<=n;i++) {
            reverse(s.begin(),s.end());
            reverse(s.begin(),s.begin()+1);
            reverse(s.begin()+1,s.end());
            int cnt = 0;
            for(int i=0;i<n-1;i++) {
                if(s[i]==s[i+1])
                    cnt++;
            }
            if(cnt==k)
                ans++;
        }
        return ans;
    }
};