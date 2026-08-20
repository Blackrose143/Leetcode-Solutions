class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n1=arr1[0],n2=arr2[0];
        for(int ind=2;ind<n;ind++){
            if(n1>n2){
                arr1.push_back(nums[ind]);
                n1=nums[ind];
            }else{
                arr2.push_back(nums[ind]);
                n2=nums[ind];
            }
        }
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};