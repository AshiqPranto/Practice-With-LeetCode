

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(int i = 0;i<ops.size();i++)
        {
            if(isdigit(ops[i].at(0)) || ops[i][0] == '-')
            {
                int temp = stoi(ops[i]);
                s.push(temp);
            }
            else if(ops[i] == "+")
            {
                int temp = s.top();
                s.pop();
                int temp1 = s.top();
                s.push(temp);
                s.push(temp+temp1);
                
            }
            else if(ops[i] == "D")
            {
                s.push(s.top()*2);
            }
            else if(ops[i] == "C"){
                s.pop();
            }
        }
        int ans = 0;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};