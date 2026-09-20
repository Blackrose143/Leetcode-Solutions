class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        long long sol=0;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++) {
            int r=intervals[i][1];
            sol += bs(r,intervals)-i;
        }
        return sol;
    }

    long long bs(int tar,vector<vector<int>>& intervals) {
        int n=intervals.size();
        int lb=0, ub=n-1, ans=0;
        while(lb<=ub) {
            int mid = (ub-lb)/2+lb;
            if(intervals[mid][0]<=tar) {
                ans = mid;
                lb = mid+1;
            }else
                ub = mid-1;
        }
        return ans;
    }
};