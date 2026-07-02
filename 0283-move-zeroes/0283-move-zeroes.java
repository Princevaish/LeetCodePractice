class Solution {
    public void moveZeroes(int[] nums) {
     int first=0;
     int second=0;
     while(second<nums.length){
        if( nums[second] != 0)
        {
            int temp=nums[second];
            nums[second]=nums[first];
            nums[first]=temp;
            first++;
        }
        second++;
     }   
    }
}