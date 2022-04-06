class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int sz = arr.size()-1;
        int ans = 0;
        for(int i = 0;i<=sz;i++)
        {
            int t = target-arr[i];
            int j = i+1;
            int k = sz;
            while(j<k)
            {
                if((arr[j]+arr[k])<t)
                {
                    j++;
                }else if((arr[j]+arr[k])>t)
                {
                    k--;
                }
                else if(arr[j]!=arr[k])
                {
                    int left = 1;
                    while(j+1<k && arr[j]==arr[j+1])
                    {
                        left++;
                        j++;
                    }
                    int right = 1;
                    while(k-1>j && arr[k] == arr[k-1])
                    {
                        right++;
                        k--;
                    }
                    ans+=left*right;
                    ans%=1000000007;
                    j++;
                    k--;
                }
                else{
                    ans+=((k-j+1)*(k-j))/2;
                    ans%=1000000007;
                    break;
                }
            }
        }
        return ans;
    }
};