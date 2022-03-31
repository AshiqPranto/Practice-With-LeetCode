class Solution {
public:
    int a[1001][51];
    int cum[1001];
    
    int dp(int j,int m)
    {
        if(a[j][m]!=-1) return a[j][m];
        if(m==1) return a[j][m] = cum[j]-cum[0];
        int ans = INT_MAX;
        for(int k = j-1;k>=1 && (k-1+1)>=(m-1) && m>=1;k--)
        {
            ans = min(ans,max(dp(k,m-1),(cum[j]-cum[k])));
        }
        return a[j][m] = ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        memset(a,-1,sizeof(a));
        for(int i = 0;i<sz;i++)
        {
            cum[i+1] = cum[i] + nums[i];
        }
        return dp(sz,m);
    }
};