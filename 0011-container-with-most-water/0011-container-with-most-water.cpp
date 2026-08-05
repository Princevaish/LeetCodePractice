class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxWater=0;
        while(i<j)
        {
            int ht=min(height[i],height[j]);
            int width=j-i;
            int currWater=ht*width;
            maxWater=max(maxWater,currWater);
            if(height[i]<height[j])
            {
                i++;
            }
            else{
                j--;
            }
        }
        return maxWater;
        
    }
};