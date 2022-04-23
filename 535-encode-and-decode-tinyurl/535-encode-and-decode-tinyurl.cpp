class Solution {
public:
    char hash = 'a';
    string base_url = "https://leetcode.com/problems/";
    map<string,string>m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // cout<<hash<<endl;
        
        string ret = base_url;
        ret+=hash;
        m[ret] = longUrl;
        // ret.push_back(hash);
        hash++;
        // cout<<"encode "<<ret<<endl;
        return ret;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // cout<<hash<<endl;
        // string temp = base_url + m[shortUrl];
        // cout<<"decode "<<temp<<endl;
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));