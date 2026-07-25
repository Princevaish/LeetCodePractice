class Solution {
public:
    void bfs(int row,int col,int n, int m, vector<vector<char>> &grid, vector<vector<int>> &vis )
    {
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};

        while(!q.empty())
        {
            int frow=q.front().first;
            int fcol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int p=frow+delr[i];
                int s=fcol+delc[i];
                if( p>=0 && p<n && s>=0 && s<m  && !vis[p][s] && grid[p][s]=='1')
                {
                    vis[p][s]=1;
                    q.push({p,s});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int count=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]== '1')
                {
                    count++;
                    bfs(row,col,n,m,grid,vis);
                }
            }
        }
        return count;
    }
};