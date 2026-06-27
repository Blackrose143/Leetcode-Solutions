class Solution {
public:

    long long mod=((int)1e9+7);
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j-1]==nums[j])
                    continue;
                int l=j+1,r=n-1;
                while(l<r){
                    long long sum=(((nums[i]+nums[j])%mod)+((nums[l]+nums[r])%mod))%mod;
                    if(sum<target)
                        l++;
                    else if(sum>target)
                        r--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        while(l<r && nums[l-1]==nums[l])
                            l++;
                    }
                }
            }
        }
        return ans;
    }
};