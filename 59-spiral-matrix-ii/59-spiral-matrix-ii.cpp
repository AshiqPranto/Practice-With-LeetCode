class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int a[n][n];
        memset(a,-1,sizeof(a));
        int L[4] = {0,1,0,-1};
        int R[4] = {1,0,-1,0};
        
        int i = 0;
        int j = 0;
        int l = 0;
        int r = 0;
        int new_i,new_j;
        
        for(int x = 1;x<=n*n;x++)
        {
            
            a[i][j] = x;
            new_i = i + L[l];
            new_j = j + R[r];
            if(new_i<0 || new_j<0 || new_i>=n || new_j>=n || a[new_i][new_j]!=-1)
            {
                l = (l+1)%4;
                r = (r+1)%4;
                
            }
            i = i + L[l];
            j = j + R[r];
        }
        vector<vector<int>>ans(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                ans[i].push_back(a[i][j]);
            }
        }
        return ans;
        
    }
};