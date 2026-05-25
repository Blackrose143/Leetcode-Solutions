class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        int st=0;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            if(idx==n-1)
                return true;
            int l=max(st + 1, idx + minJump );
            int r=min(idx + maxJump, n - 1);
            for(int k=l;k<=r;k++)
                if(s[k]=='0' && !vis[k]){
                    vis[k]=1;
                    q.push(k);
            }
            st=max(st,r);
        }
        return false;
    }
};