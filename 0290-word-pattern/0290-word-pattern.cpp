class Solution {
public:
    bool wordPattern(string pattern, string s) {
     vector<string> v;
     string word;
     stringstream ss(s); 

     while(ss>> word)
     {
        v.push_back(word);
     } 

     unordered_map<char,string> pts;
     unordered_map<string,char> stp;
     
     if(pattern.size()!=v.size()) return false;

     for(int i=0;i<pattern.size();i++)
     {
        char c1=pattern[i];
        string s1=v[i];

        if(pts.count(c1))
        {
            if(pts[c1]!=s1) return false;
        }
        else{
        if(stp.count(s1)) return false;
        }
        pts[c1]=s1;
        stp[s1]=c1;
     }
     return true;
    }
};