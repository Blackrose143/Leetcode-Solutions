class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0],n=nums.size();
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        for(int i=1;i<n;i++) {
            if(nums[i]==nums[i-1]+1)
                sum += nums[i];
            else
                break;
        }
        while(sum) {
            if(mp.find(sum)==mp.end())
                return sum;
            sum += 1;
        }
        return -1;
    }
};