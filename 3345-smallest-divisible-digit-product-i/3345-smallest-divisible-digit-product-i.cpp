class Solution {
public:
    int smallestNumber(int n, int t) {
        int m=n;
        while(true){
            int val=1;
            while(m){
                int mod = m%10;
                val *= mod;
                m /= 10;
                if(val==0)
                    return n;
            }
            if(val%t==0)
                return n;
            n += 1;
            m = n;
        }
        return 0;
    }
};