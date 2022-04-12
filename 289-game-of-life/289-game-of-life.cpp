class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int x[8] = {-1,+1,0,0,-1,-1,+1,+1};
        int y[8] = {0,0,-1,+1,-1,+1,-1,+1};
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans = board;
        int new_i,new_j;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int cnt = 0;
                for(int k = 0;k<8;k++)
                {
                    new_i = i+x[k];
                    new_j = j+y[k];
                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && board[new_i][new_j])
                    {
                        cnt++;
                    }
                }
                if(cnt<2) ans[i][j] = 0;
                else if(cnt == 3) ans[i][j] = 1;
                else if(cnt > 3) ans[i][j] = 0;
                else ans[i][j] = board[i][j];
            }
        }
        board = ans;
        
    }
};