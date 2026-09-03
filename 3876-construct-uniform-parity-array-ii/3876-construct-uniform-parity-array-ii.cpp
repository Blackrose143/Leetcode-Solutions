class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        bool odd = false;
        for(int x:nums1) {
            if(x%2 != nums1[0]%2) return odd;
            if(x%2==1)
                odd = true;
        }
        return true;
    }
};