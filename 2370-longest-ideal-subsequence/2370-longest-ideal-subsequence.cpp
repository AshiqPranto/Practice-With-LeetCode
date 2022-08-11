class Solution {
public:
    int longestIdealString(string s, int k) {
        
        map<int,int>cnt;
        
        int sz = s.size();
        // for(int i = 0;i<sz;i++) cnt[s[i]] = 1;
        
        int dp[100005];
        memset(dp,1,sizeof(dp));
        
        int ans = 0;
        
        for(int i = sz-1;i>=0;i--)
        {
            int num = s[i];
            int maximum = 0;
            int tempNum = num;
            for(int j = num; j<=(num+k) && j<=122;j++)
            {
                maximum = max(maximum,cnt[j]);
            }
            for(int j = num; j>=(num-k) && j>=97;j--)
            {
                maximum = max(maximum,cnt[j]);
            }
            dp[i] = maximum+1;
            cnt[s[i]] = dp[i];
            
            ans = max(ans,dp[i]);
        }
        return ans;
        //97 - 122
        // s[0] = 'z';
        // int num = s[0];
        // cout<<num;
        // return 0;
        
    }
};