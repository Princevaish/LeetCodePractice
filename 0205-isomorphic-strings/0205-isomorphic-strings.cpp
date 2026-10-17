class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> mps;
        unordered_map<char,char> mpt;
        for(int i=0;i<s.size();i++)
        {
            char c1=s[i];
            char c2=t[i];
            if(mps.count(c1))
            {
                if(mps[c1]!=c2) return false;
            }
            else
            {
                if(mpt.count(c2)) return false;
            }
            mps[c1]=c2;
            mpt[c2]=c1;
        }
    return true;
    }
};