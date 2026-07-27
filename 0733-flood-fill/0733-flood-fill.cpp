class Solution {
public:
    void dfs(vector<vector<int>> &image,vector<vector<int>> &ans,int sr, int sc ,int n,int m,int color,int iniColor)
    {
        ans[sr][sc]=color;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int strow= sr + delr[i];
            int stcol= sc + delc[i];
            if(strow>=0 && strow<n && stcol>=0 && stcol<m && ans[strow][stcol]!=color && image[strow][stcol]==iniColor)
            {
                dfs(image,ans,strow,stcol,n,m,color,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int n=image.size();
        int m=image[0].size();
        dfs(image,ans,sr,sc,n,m,color,iniColor);
        return ans;
    }
};