
class Solution {
public:

    bool helper(int i, int bucketNumber, int reqSum, int k,
                int mask, vector<int>& nums,
                vector<vector<int>>& dp, int target) {

        if (bucketNumber == k + 1) return true;

        if (reqSum == 0) {
            return helper(0, bucketNumber + 1, target,
                          k, mask, nums, dp, target);
        }

        if (reqSum < 0) return false;
        if (i >= nums.size()) return false;

        // Check memoization
        if (dp[mask][i] != -1) {
            return dp[mask][i];
        }

        // Already picked
        if (mask & (1 << i)) {
            return dp[mask][i] = helper(
                i + 1, bucketNumber, reqSum,
                k, mask, nums, dp, target
            );
        }

        // Pick
        bool op1 = helper(
            i + 1, bucketNumber, reqSum - nums[i],
            k, mask | (1 << i), nums, dp, target
        );

        // Not Pick
        bool op2 = helper(
            i + 1, bucketNumber, reqSum,
            k, mask, nums, dp, target
        );

        return dp[mask][i] = op1 || op2;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        int target = sum / k;

        vector<vector<int>> dp(
            1 << n, vector<int>(n + 1, -1)
        );

        return helper(0, 1, target, k, 0,
                      nums, dp, target);
    }
};
