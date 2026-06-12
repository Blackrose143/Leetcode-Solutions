class Solution {
public:
    int numSquares(int n) {
        vector<int> ps(n+1,INT_MAX);
        ps[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                ps[i]=min(ps[i],ps[i-j*j]+1);
            }
        }
        return ps[n];
    }
};