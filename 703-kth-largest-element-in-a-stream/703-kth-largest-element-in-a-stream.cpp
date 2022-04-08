class KthLargest {
public:
    int k1;
    priority_queue<int,vector<int>,greater<int> > p;
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for(int num : nums) p.push(num);
    }
    
    int add(int val) {
        p.push(val);
        while(p.size()>k1) p.pop();
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */