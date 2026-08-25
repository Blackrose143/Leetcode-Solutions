class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int m=k;
        for(int i:nums)
            mp[i]++;
        while(k) {
            if(mp.find(k)==mp.end())
                return k;
            k += m;
        }
        return -1;
    }
};