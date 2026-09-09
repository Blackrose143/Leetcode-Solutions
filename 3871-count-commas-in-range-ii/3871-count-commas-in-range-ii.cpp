class Solution {
public:

    long long countCommas(long long n) {
        long long sol = 0;
        if(n<999)
            return sol;
        sol += (n-999);
        if(n>=1e6)
            sol += (n-1e6+1);
        if(n>=1e9)
            sol += (n-1e9+1);
        if(n>=1e12)
            sol += (n-1e12+1);
        if(n>=1e15)
            sol += (n-1e15+1);
        return sol;
    }
};