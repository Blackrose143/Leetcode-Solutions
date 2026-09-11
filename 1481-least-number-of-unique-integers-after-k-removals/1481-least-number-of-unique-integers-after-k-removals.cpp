class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;

        vector<int> freq;
        for(auto pi:mp) {
            int F = pi.second;
            freq.push_back(F);
        }

        sort(freq.begin(),freq.end());

        int n = freq.size();
        for(int i=0;i<n;i++) {
            k -= freq[i];
            if(k==0)
                return n-i-1;
            if(k<0)
                return n-i;
        }
        return n;
    }
};