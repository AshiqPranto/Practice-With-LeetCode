class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+5];
        for(int i =0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> side(n+5, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int st = 1; st <= n; ++st) {
            if (side[st] == -1) {
                q.push(st);
                side[st] = 0;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int u : adj[v]) {
                        if (side[u] == -1) {
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= side[u] != side[v];
                        }
                    }
                }
            }
        }
        return is_bipartite;
    }
};