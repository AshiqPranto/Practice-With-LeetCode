class Solution {
public:
    
    long long findCost(vector<int>& nums,vector<int>& cost,int x)
    {
        long long ans = (long long)0;
        for(int i = 0;i<nums.size();i++)
        {
            ans+=abs(nums[i]-x)*(long long)cost[i];
        }
        return ans;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int left = 100000000,right = 0;
        for(int num:nums)
        {
            left = min(left,num);
            right = max(right,num);
        }
        long long ans = 0;
        while(left<right)
        {
            int mid = (left+right)/2;
            long long y1 = findCost(nums,cost,mid);
            long long y2 =  findCost(nums,cost,mid+1);
            
            if(y1<=y2)
            {
                right = mid;
                ans = y1;
            }else if(y1>=y2)
            {
                ans = y2;
                left = mid+1;
            }
        }
        return ans;
        
    }
};