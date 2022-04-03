class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int cnt[105] = {0};
        bool check = false;
        for(int i = sz-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            {
                check = true;
                vector<int>a;
                int j = i-1;
                for(;j<sz;j++) a.push_back(nums[j]);
                sort(a.begin(),a.end());
                int temp = upper_bound(a.begin(),a.end(),nums[i-1])-a.begin();
                nums[i-1] = a[temp];
                a[temp] = 200;
                sort(a.begin(),a.end());
                // a.erase(upper_bound(a.begin(),a.end(),nums[i-1]));
                // a.erase(temp);
                for(j = 0;j<a.size()-1;j++,i++) nums[i] = a[j];
                break;
            }
        }
        if(!check)
        {
            sort(nums.begin(),nums.end());
        }
    }
};