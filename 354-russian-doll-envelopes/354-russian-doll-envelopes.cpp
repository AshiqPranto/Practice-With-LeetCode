class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),cmp);
        
        vector<int>lis;
        int n = envelopes.size();
        for(int i = 0;i<n;i++)
        {
            int x = envelopes[i][1];
            int idx = lower_bound(lis.begin(),lis.end(),x) - lis.begin();
            if(idx>=lis.size())
            {
                lis.push_back(x);
            }
            else lis[idx] = x;
        }
        return lis.size();
    }
};