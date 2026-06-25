class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cnt=0,ans=0;
        for(int num:nums)
            if(num==0)
                cnt++;
        for(int r=nums.size()-1;r>=0;r--){
            if(nums[r]==0){
                cnt--;
            }else if(cnt && nums[r]!=0){
                ans++;
                cnt--;
            }
            if(cnt==0)
                break;
        }
        return ans;
    }
};