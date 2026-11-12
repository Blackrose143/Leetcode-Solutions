class Solution {
public:
    int findIntegers(int n) {
        vector<int> dpZeros(32),dpOnes(32),dp(32);
        dpZeros[0] = dp[0] = 1;
        for(int i=1;i<32;i++) {
            dpOnes[i] = dpZeros[i-1];
            dpZeros[i] = dpZeros[i-1] + dpOnes[i-1];
            dp[i] = dpZeros[i] + dpOnes[i];
        }

        int ans = 0, lastbit = 0;
        for(int k=30;k>=0;k--) {
            int bit = (n>>k) & 1;
            if(bit==1) {
                ans += dp[k];
                if(lastbit==1)
                    return ans;
            }
            lastbit = bit;
        }
        return ans+1;
    }
};