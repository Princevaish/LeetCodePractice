class Solution {
public:
    void bfs(int node, vector<int>& vis, vector<vector<int>>& isConnected)
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int adj = 0; adj < isConnected.size(); adj++)
            {
                if (isConnected[curr][adj] == 1 && !vis[adj])
                {
                    vis[adj] = 1;
                    q.push(adj);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();

        vector<int> vis(n, 0);

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                bfs(i, vis, isConnected);
            }
        }

        return count;
    }
};