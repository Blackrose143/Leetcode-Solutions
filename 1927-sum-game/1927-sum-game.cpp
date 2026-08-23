class Solution {
public:

    double fun(char c) {
        return c == '?'?4.5:c-'0';
    }

    bool sumGame(string num) {
        int n=num.size();
        double ans = 0.0;
        for(int i=0;i<(n/2);i++)
            ans += fun(num[i]);
        for(int i=n/2;i<n;i++)
            ans -= fun(num[i]);
        return ans != 0.0;
    }
};