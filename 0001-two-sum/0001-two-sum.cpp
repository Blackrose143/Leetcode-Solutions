class Solution {
public:

    int n;
    vector<int> solve(vector<int>& nums,int target){

        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(target-nums[i]) != m.end()){
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]]=i;
        }
        return ans;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        n=nums.size();
        return solve(nums,target);
    }
};