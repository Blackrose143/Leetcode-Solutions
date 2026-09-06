class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long n = nums.size(), ans = 0;
        long long ls = accumulate(nums.begin(),nums.begin()+(n/2),0LL);
        long long rs = accumulate(nums.begin()+(n/2),nums.end(),0LL);
        int l = 0, r = n/2;
        for(int i=0;i<n;i++) {
            if(ls>rs)
                ans++;
            cout << l << ' ' << r << '\n';
            ls -= nums[l];
            ls += nums[r];
            rs -= nums[r];
            rs += nums[l];
            l = ((l+1)%n);
            r = ((r+1)%n);
        }
        return ans;
    }
};