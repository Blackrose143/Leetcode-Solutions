class Solution {
    public long countCommas(long n) {
        long tot = 0;
        long start = 1000;
        while(start<=n) {
            tot += (n-start+1);
            start *= 1000;
        }
        return tot;
    }
}