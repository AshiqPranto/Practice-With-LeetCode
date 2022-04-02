class Solution {
public:
    bool checkPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        string r = s;
        // reverse(r.begin(),r.end());
        int sz = s.size();
        int i = 0;
        int j = sz-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return (checkPalindrome(s,i,j-1)||checkPalindrome(s,i+1,j));
            }
            i++;
            j--;
        }
        return true;
    }
};