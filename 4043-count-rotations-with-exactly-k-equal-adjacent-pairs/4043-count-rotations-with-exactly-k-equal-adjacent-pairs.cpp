class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length(), cnt = 0;
        for(int i=0;i<n;i++) {
            if(s[i]==s[(i+1)%n])
                cnt++;
        }
        if(cnt==k)
            return n-cnt;
        else if(cnt-1==k)
            return cnt;
        return 0;
    }
};