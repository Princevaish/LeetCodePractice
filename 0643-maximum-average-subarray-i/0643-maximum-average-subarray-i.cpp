class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg= -DBL_MAX;
        int i=0;
        double count=0;
        for(int j=0;j<nums.size();j++)
        {
            count=count+nums[j];
            if(j-i+1==k)
            {
                double avg=count/k;
                maxavg=max(maxavg,avg);
                count-=nums[i];
                i++;  
            }
        }
        return maxavg;
    }
};