class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp; 
        mp[0] = 1; // empty prefix

        int prefix = 0;
        int count = 0;

        for(int x : nums) {
            prefix += x;

            
            if(mp.count(prefix - goal))
                count += mp[prefix - goal];

            mp[prefix]++;
        }
        return count;
    }
};
