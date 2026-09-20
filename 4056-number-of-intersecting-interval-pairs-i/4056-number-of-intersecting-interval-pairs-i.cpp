class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size(),ans=0;

        for(int i=0;i<n;i++) {
            int l=intervals[i][0], r=intervals[i][1];
            for(int j=i+1;j<n;j++) {
                if(!(r<intervals[j][0] || l>intervals[j][1]))
                    ans++;
            }
        }
        return ans;
    }
};