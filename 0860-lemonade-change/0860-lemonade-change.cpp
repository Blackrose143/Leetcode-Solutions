class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0, t=0, n=bills.size();
        for(int i=0;i<n;i++){
            int rem = bills[i] - 5;
            if(bills[i]==10)
                t += 1;
            if(bills[i]==5)
                f += 1;
            while(t && rem>=10){
                t -= 1;
                rem -= 10;
            }
            while(f && rem>=5){
                f -= 1;
                rem -= 5;
            }
            if(rem)
                return false;
        }
        return true;
    }
};