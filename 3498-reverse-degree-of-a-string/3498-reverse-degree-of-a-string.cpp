class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0,cnt=1;
        for(char c:s) {
            int val = ('z'-c+1)*cnt;
            cnt++;
            ans += val;
        }
        return ans;
    }
};