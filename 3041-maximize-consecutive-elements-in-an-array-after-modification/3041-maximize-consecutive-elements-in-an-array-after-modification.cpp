class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        for(int x:nums) {
            mp[x+1] = mp[x]+1;
            mp[x] = mp[x-1]+1;
            ans = max({ans,mp[x],mp[x+1]});
        }
        return ans;
    }
};