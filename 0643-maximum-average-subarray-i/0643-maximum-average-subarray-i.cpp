class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double average = 0;
        int i = 0;
        int j = 0;
        double sum = 0;
        double maxavg = INT_MIN;

        // Create first window of size k
        while (j < k)
        {
            sum = sum + nums[j];
            j++;
        }

        // Process first window
        average = sum / k;
        maxavg = max(maxavg, average);

        // Slide the window
        while (j < nums.size())
        {
            sum = sum + nums[j];
            sum = sum - nums[i];

            average = sum / k;
            maxavg = max(maxavg, average);

            j++;
            i++;
        }

        return maxavg;
    }
};