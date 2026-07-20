class Solution {
public:

    int n,m;
    void fun(int i,int j,vector<vector<int>>& grid){
        while(i<j){
            swap(grid[i/m][i%m],grid[j/m][j%m]);
            i++;
            j--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        int tot = n*m;
        k = ( k % tot );
        if(!k)
            return grid;

        fun(0,tot-1,grid);
        fun(0,k-1,grid);
        fun(k,tot-1,grid);
        return grid;
    }
};