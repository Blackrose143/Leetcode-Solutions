class Solution {
public:

    int n,m;
    int fun(vector<vector<int>>& std, vector<vector<int>>& men, vector<int>& vis,int idx) {
        if(idx==n)
            return 0;

        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i])
                continue;

            int cnt = 0;
            for(int j=0;j<m;j++){
                if(std[idx][j]==men[i][j])
                    cnt++;
            }

            vis[i] = 0;
            ans = max(ans, cnt+fun(std,men,vis,idx+1));
            vis[i] = 1;
        }
        return ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students.size();
        m = students[0].size();

        vector<int> vis(n,1);
        return fun(students,mentors,vis,0);
    }
};