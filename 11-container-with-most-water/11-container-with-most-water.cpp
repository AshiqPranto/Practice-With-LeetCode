class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int ans = 0;
        for(int i = 0,j = sz-1;i<j; )
        {
            ans = max(ans,(min(height[i],height[j])*(j-i)));
            if(height[i]<height[j]) i++;
            else if(height[i]>height[j]) j--;
            else i++,j--;
        }
        return ans;
    }
};