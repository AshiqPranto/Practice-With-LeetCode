class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>cnt;
        int sz = nums.size();
        for(int i = 0;i<sz;i++) cnt[nums[i]]++;
        priority_queue<pair<int,int> >pq;
        for(auto it : cnt)
        {
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        for(int i = 0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};