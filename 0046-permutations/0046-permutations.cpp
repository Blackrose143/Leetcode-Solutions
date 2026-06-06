class Solution {
public:

    int n;
    vector<vector<int>> ans;
    void rec(int cnt,vector<int>& nums){
        if(n==cnt){
            ans.push_back(nums);
            return;
        }
        for(int i=cnt;i<n;i++){
            swap(nums[i],nums[cnt]);
            rec(cnt+1,nums);
            swap(nums[i],nums[cnt]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        rec(0,nums);
        return ans;
    }
};