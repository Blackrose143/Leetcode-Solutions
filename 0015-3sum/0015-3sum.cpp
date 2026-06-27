class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i])
                continue;
            unordered_map<int,int> mp;
            for(int j=i+1;j<n;j++){
                int t=-(nums[i]+nums[j]);
                if(mp.find(t)!=mp.end())
                    ans.insert({nums[i],nums[j],t});
                mp[nums[j]]++;
            }
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};