class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans = grid;
        int n = grid.size();
        int m = grid[0].size();
        int new_i,new_j;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                new_j = (j+k)%m;
                new_i = (i+((j+k)/m))%n;
                ans[new_i][new_j] = grid[i][j];
            }
        }
        return ans;
    }
};