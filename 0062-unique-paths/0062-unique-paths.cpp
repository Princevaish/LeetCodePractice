class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return uniquePathsHelper(0, 0, m, n, dp);
    }

private:
    int uniquePathsHelper(int i, int j, int m, int n,
                          vector<vector<int>>& dp) {

        if (i >= m || j >= n) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int right = uniquePathsHelper(i, j + 1, m, n, dp);
        int down = uniquePathsHelper(i + 1, j, m, n, dp);

        return dp[i][j] = right + down;
    }
};