class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        
        for(auto& edge : prerequisites)
        {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        vector<int> topoSort;
        queue<int> q;

        
        for(int node = 0; node < numCourses; node++)
        {
            if(indegree[node] == 0)
            {
                q.push(node);
            }
        }

        
        while(!q.empty())
        {
            int firstNode = q.front();
            q.pop();

            topoSort.push_back(firstNode);

            for(int node : adj[firstNode])
            {
                indegree[node]--;

                if(indegree[node] == 0)
                {
                    q.push(node);
                }
            }
        }

        
        if(topoSort.size() != numCourses)
        {
            return {};
        }

        return topoSort;
    }
};