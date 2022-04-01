class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        int temp;
        for(int i = 0,j = sz-1;i<j;i++,j--)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        for(int i = 0;i<sz;i++) cout<<s[i];
    }
};