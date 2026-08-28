class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x:nums)
            mp[x]++;
        for(auto pi:mp)
            if(pi.second==1)
                return pi.first;
        return -1;
    }
};