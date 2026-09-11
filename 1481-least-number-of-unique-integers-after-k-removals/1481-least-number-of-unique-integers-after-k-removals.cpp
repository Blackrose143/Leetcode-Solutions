class Solution {
public:

    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        if(k==0)
            return mp.size();
        vector<pair<int,int>> vc;
        for(auto pi:mp) {
            vc.push_back({pi.second,pi.first});
        }
        sort(vc.begin(),vc.end());

        int cnt = 0;
        for(auto v:vc) {
            int x=v.second;
            while(true) {
                mp[x]--;
                cnt++;
                if(mp[x]==0) {
                    mp.erase(x);
                    break;
                }
                if(cnt==k)
                    break;
            }
            if(cnt==k)
                break;
        }
        return mp.size();
    }
};