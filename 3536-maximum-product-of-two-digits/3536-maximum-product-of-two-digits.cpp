class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;
        while(n){
            int rem=n%10;
            ans.push_back(rem);
            n/=10;
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-2]*ans.back();
    }
};