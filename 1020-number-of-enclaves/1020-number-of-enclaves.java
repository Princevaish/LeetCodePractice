class Solution {

    public void dfs(int row, int col, int[][] vis, int[][] grid, int[] delRow, int[] delCol) {

        vis[row][col] = 1;

        int n = grid.length;
        int m = grid[0].length;

        for (int i = 0; i < 4; i++) {

            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n &&
                nCol >= 0 && nCol < m &&
                vis[nRow][nCol] == 0 &&
                grid[nRow][nCol] == 1) {

                dfs(nRow, nCol, vis, grid, delRow, delCol);
            }
        }
    }

    public int numEnclaves(int[][] grid) {

        int n = grid.length;
        int m = grid[0].length;

        int[][] vis = new int[n][m];

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        
        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 1 && vis[0][j] == 0) {
                dfs(0, j, vis, grid, delRow, delCol);
            }

            if (grid[n - 1][j] == 1 && vis[n - 1][j] == 0) {
                dfs(n - 1, j, vis, grid, delRow, delCol);
            }
        }

        
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 1 && vis[i][0] == 0) {
                dfs(i, 0, vis, grid, delRow, delCol);
            }

            if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0) {
                dfs(i, m - 1, vis, grid, delRow, delCol);
            }
        }

        int count=0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count=count+1;
                }
            }
        }
        return count;
    }
}