class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int sz = nums.size();
        int ans = 0;
        for(int i = 0;i<sz;i++)
        {
            int gcd = nums[i];
            if(gcd == k) ans++;
            for(int j = i+1;j<sz;j++)
            {
                gcd = __gcd(gcd,nums[j]);
                if(gcd == k) ans++;
            }
        }
        return ans;
    }
};