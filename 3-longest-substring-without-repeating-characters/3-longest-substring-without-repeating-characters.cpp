class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int maxlen = 0;
        int lastRepeat = -1;
        map<char,int> has;
        for(int i = 0;i<s.size();i++)
        {
            if(has.find(s[i])!=has.end())
            {
                // cout<<"i = "<<i<<endl;
                lastRepeat = max(lastRepeat,has[s[i]]);
                len = i - lastRepeat;
                has[s[i]] = i;
                maxlen = max(maxlen,len);
            }
            else
            {
                len++;
                has[s[i]] = i;
                maxlen = max(maxlen,len);
            }
        }
        return maxlen;
    }
};