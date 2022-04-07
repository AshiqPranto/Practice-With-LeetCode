class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i = 0;i<stones.size();i++) pq.push(stones[i]);
        int ans ;
        while(!pq.empty())
        {
            ans = pq.top();
            pq.pop();
            if(!pq.empty())
            {
                ans = ans - pq.top();
                pq.pop();
                pq.push(ans);
            }
        }
        return ans;
    }
};