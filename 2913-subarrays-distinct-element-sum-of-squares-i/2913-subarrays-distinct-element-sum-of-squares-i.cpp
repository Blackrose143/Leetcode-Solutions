class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp.clear();
            for(int j=i;j<n;j++) {
                mp[nums[j]]++;
                ans += (mp.size()*mp.size());
            }
        }
        return ans;
    }
};