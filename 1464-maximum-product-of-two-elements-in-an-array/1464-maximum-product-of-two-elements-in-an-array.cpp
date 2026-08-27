class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=-1e9,sm=-1e9;
        for(int i:nums) {
            if(i>mx){
                sm = mx;
                mx = i;
            }else if(i>sm)
                sm = i;
        }
        return (mx-1)*(sm-1);
    }
};