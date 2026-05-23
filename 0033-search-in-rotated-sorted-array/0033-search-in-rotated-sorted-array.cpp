class Solution {
public:

    int n ;

    int rotate(vector<int>& nums){

        int low = 0 , high = n - 1 , mid;
        while(low < high){

            mid = low + (high - low)/2;

            if(nums[mid] <= nums[high])
                high = mid ;
            else
                low = mid + 1 ;
        }
        return low ;
    }   

    int BSearch(vector<int>& nums , int key , int r){

        int low = 0 , high = n - 1 , mid  , rmid;
        
        while(low <= high){

            mid = low + (high - low )/2  ;
            rmid = (mid + r) % n; 
            if(nums[rmid] == key){
                return rmid;
            }else if(nums[rmid] < key)
                low = mid + 1;
            else
                high = mid - 1;

        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        n = nums.size();
         if (n == 1) return nums[0] == target ? 0 : -1;
        int r = rotate(nums);

        return BSearch(nums,target,r);

    }
};