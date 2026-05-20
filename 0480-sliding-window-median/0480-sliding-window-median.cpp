class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<double> ms;
        vector<double> ans;
        for(int i=0;i<k;i++)
            ms.insert(nums[i]);
        auto mid=next(ms.begin(),(k-1)/2);
        if(k%2)
            ans.push_back(*mid);
        else
            ans.push_back((*mid+*(next(mid)))/2);
        for(int i=k;i<n;i++){
            ms.insert(nums[i]);
            if(nums[i]<*mid)
                mid--;
            if(nums[i-k]<=*mid)
                mid++;
            ms.erase(ms.find(nums[i-k]));
            if(k%2)
                ans.push_back(*mid);
            else
                ans.push_back((*mid+*(next(mid)))/2);
        }
        return ans;
    }
};