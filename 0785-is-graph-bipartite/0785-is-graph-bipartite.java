import java.util.*;

class Solution {

    public boolean bfs(int start, int[] color, int[][] graph) {

        Queue<Integer> q = new LinkedList<>();

        q.offer(start);
        color[start] = 0;

        while (!q.isEmpty()) {

            int node = q.poll();

            for (int adjNode : graph[node]) {

                if (color[adjNode] == -1) {

                    color[adjNode] = 1 - color[node];
                    q.offer(adjNode);
                }
                else if (color[adjNode] == color[node]) {

                    return false;
                }
            }
        }

        return true;
    }

    public boolean isBipartite(int[][] graph) {

        int n = graph.length;

        int[] color = new int[n];

        Arrays.fill(color, -1);

        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                if (!bfs(i, color, graph))
                    return false;
            }
        }

        return true;
    }
}