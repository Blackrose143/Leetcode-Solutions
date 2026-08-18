class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==k)
            return *max_element(nums.begin(),nums.end());
        
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        
        if(k==1) {
            int mx = -1;
            for(int i:nums)
                if(mp[i]==1 && i>mx)
                    mx = i;
            return mx;
        }

        n = n-1;
        if(nums[0]==nums[n])
            return -1;

        if(mp[nums[0]]==1 && mp[nums[n]]==1)
            return max(nums[0],nums[n]);

        if(mp[nums[0]]==1 && mp[nums[n]]>1)
            return nums[0];

        if(mp[nums[n]]==1 && mp[nums[0]]>1)
            return nums[n];
            
        return -1;
    }
};