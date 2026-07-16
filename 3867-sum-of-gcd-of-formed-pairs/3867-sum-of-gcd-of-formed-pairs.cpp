class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n=nums.size();
        vector<int> prf(n);

        int mx=-1e9;
        for(int i=0;i<n;i++){
            if(nums[i]>mx)
                mx = nums[i];
            prf[i] = gcd(mx,nums[i]);
        }

        sort(prf.begin(),prf.end());

        long long i=0,j=prf.size()-1,ans=0;
        while(i<j){
            ans += gcd(prf[i],prf[j]);
            i++;
            j--;
        }

        return ans;
    }
};