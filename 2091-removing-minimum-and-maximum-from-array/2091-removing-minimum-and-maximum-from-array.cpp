class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        vector<pair<int,int>> vp(2);
        vp[0] = {1e5,-1};
        vp[1] = {0,-1};
        for(int i=0;i<n;i++) {
            if(nums[i]>vp[1].first)
                vp[1] = {nums[i],i};
            if(nums[i]<vp[0].first)
                vp[0] = {nums[i],i};
        }
        int mi=vp[0].second,mx=vp[1].second;
        if(mi<mx) {
            return min({(mi+1)+(n-mx),mx+1,n-mi});
        }
        return min({(mx+1)+(n-mi),mi+1,n-mx});
    }
};