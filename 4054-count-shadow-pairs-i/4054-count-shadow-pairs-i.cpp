class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        
        long long n=nums.size(),ans=0;

        vector<int> st;
        for(int x:nums) {
            while(!st.empty() && x<st.back())
                st.pop_back();
            int bound=lower_bound(st.begin(),st.end(),x)-st.begin();
            ans += bound;
            st.push_back(x);
        }
        return ans;
    }
};