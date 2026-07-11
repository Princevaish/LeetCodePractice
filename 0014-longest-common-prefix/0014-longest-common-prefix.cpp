class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        for(int i=0;i<strs[0].size();i++)
        {
            char ch=strs[0][i];
            bool found=true;
            for(int j=1;j<n;j++)
            {
                if(strs[j].size()<=i || strs[j][i]!=ch)
                {
                   found=false;
                   break;
                }

            }
                if(found == false)
                {
                    break;
                }
                else
                {
                    ans=ans+ch;
                }
        }
        return ans;
    }
};