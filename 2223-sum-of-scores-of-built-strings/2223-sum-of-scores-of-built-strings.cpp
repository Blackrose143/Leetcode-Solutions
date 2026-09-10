class Solution {
public:
    long long sumScores(string s) {
        int n = s.length();
        int l = 0, r = 0;
        long long ans = 0;
        vector<int> z(n);
        for(int i=1;i<n;i++) {

            if(i<=r)
                z[i] = min(z[i-l],r-i+1);

            while(i+z[i]<n && s[z[i]]==s[i+z[i]])
                z[i]++;

            if(i+z[i]-1 > r) {
                l = i;
                r = i+z[i]-1;
            }
            ans += z[i];
        }
        return n+ans;
    }
};