class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int currentSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            currentSum=currentSum+nums[i];
            maxSum=max(currentSum,maxSum);
            if(currentSum<0)
            {
                currentSum=0;
            }
        }
        return maxSum;
    }
};