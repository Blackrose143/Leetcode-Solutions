class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int n = digits.size();
        int ans = 0;

        vector<int> vis(10,0);
        for(int i:digits)
            vis[i]++;

        for(int i=1;i<10;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<9;k+=2)
                    ans += ((vis[i]>0) && (vis[j]>(i==j)) && (vis[k]>(i==k)+(j==k)));

        return ans;
    }
};