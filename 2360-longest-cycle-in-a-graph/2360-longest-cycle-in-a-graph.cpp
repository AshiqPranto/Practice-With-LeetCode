class Solution {
public:
    
    
    int dp[100005];
    int ans = -1;
    bool vis[100005];
    int dis[100005];
    vector<int> edges;
    bool extra[100005];
    
    void bfs(int x)
    {
        
        memset(extra,0,sizeof(extra));
        
        vis[x] = 1;
        extra[x] = 1;
        dis[x] = 1;
        
        queue<int> q;
        if(edges[x]!=-1)
            q.push(edges[x]);
        int temp;
        int prev = x;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            // if(dp[temp]>0)
            // {
            //     int y = x;
            //     while(y!=temp)
            //     {
            //         dp[y] = dp[temp];
            //         y = edges[y];
            //     }
            //     return dp[temp];
            // }else if(dp[temp]==-1)
            // {
            //     return 0;
            // }
            if(vis[temp])
            {
                if(extra[temp])
                {
                    ans = max(ans,(dis[prev]-dis[temp]+1));
                }
                // int store = dis[prev]-dis[temp]+1;
                // int y = temp;
                // while(y!=prev)
                // {
                //     dp[y] = store;
                //     y = edges[y];
                // }
                // dp[prev] = store;
                // return store;
            }
            else{
                vis[temp] = true;
                extra[temp] = true;
                dis[temp] = dis[prev]+1;
                if(edges[temp]!=-1)
                    q.push(edges[temp]);
                prev = temp;
            }
        }
        // int y = x;
        // while(y!=prev)
        // {
        //     dp[y] = -1;
        //     y = edges[y];
        // }
        // return 0;
    }
    
    int longestCycle(vector<int>& edge) {
        
        
        edges = edge;
        int n = edges.size();
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                bfs(i);
            }
//                 if(dp[i]>0)
//                 {
//                     ans = max(ans,dp[i]);
//                 }else if(dp[i]<0) continue;
//                 else{
                    
//                     ans = max(ans,bfs(i,n));    
//                 }
        }
        return ans;
    }
};