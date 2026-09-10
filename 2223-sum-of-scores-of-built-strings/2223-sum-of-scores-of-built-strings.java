class Solution {
    public long sumScores(String s) {
        int n = s.length();
        int l = 0, r = 0;
        long ans = 0;

        List<Integer> z = new ArrayList<>(Collections.nCopies(n,0));
        for(int i=1;i<n;i++) {
            if(i<=r)
                z.set(i,Math.min(z.get(i-l),r-i+1));

            while( i + z.get(i) < n && s.charAt(z.get(i)) == s.charAt(i+z.get(i)) )
                z.set(i,z.get(i)+1);

            if( i + z.get(i) - 1 > r ) {
                l = i;
                r = i + z.get(i) - 1;
            }

            ans += z.get(i);
        }
        return n+ans;
    }
}