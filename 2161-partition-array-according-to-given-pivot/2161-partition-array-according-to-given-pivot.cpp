class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int left=0,right=n-1;
        vector<int> ans(n),vis(n);
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[left++]=nums[i];
                vis[i]=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>pivot){
                ans[right--]=nums[i];
                vis[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)
                ans[left++]=pivot;
        }
        return ans;
    }
};