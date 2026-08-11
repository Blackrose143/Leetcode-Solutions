class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mi = nums[0];
        int mx = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++){
            int x = nums[i];

            if(x<0)
                swap(mx,mi);

            mx = max(x, mx*x);
            mi = min(x, mi*x);
            ans = max(ans, mx);
        }
        return ans;
    }
};