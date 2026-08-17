class Solution {
public:
    using ll = long long;

    vector<vector<int>> dp;
    vector<ll> prefix;

    int fun(int l, int r) {
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int k = l; k < r; k++) {

            ll leftSum = prefix[k + 1] - prefix[l];
            ll rightSum = prefix[r + 1] - prefix[k + 1];

            if (leftSum < rightSum) {
                ans = max(ans, (int)(leftSum + fun(l, k)));
            }
            else if (rightSum < leftSum) {
                ans = max(ans, (int)(rightSum + fun(k + 1, r)));
            }
            else {
                ans = max(ans, (int)(leftSum + fun(l, k)));
                ans = max(ans, (int)(rightSum + fun(k + 1, r)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        dp.assign(n, vector<int>(n, -1));

        return fun(0, n - 1);
    }
};