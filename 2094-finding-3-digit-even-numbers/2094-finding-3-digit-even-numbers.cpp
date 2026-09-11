class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        int n = digits.size();

        vector<int> vis(10),ans;

        for(int i:digits)
            vis[i]++;

        for(int i=1;i<10;i++) 
            for(int j=0;j<10;j++)
                for(int k=0;k<9;k+=2) {
                    if(vis[i]>0 && vis[j]>(i==j) && vis[k]>(i==k)+(j==k)) {
                        int val = i*100 + j*10 + k;
                        ans.push_back(val);
                    }
                }

        return ans;
    }
};