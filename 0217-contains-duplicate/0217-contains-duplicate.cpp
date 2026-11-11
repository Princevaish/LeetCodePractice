class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int num:nums)
        {
            if(mp.find(num)==mp.end())
            {
                mp[num]=true;
            }
            else
            {
                mp[num]=false;
            }
        }
        for(auto &it: mp)
        {
            if(it.second==false)
            {
                return true;
            }
        }
        return false;
    }
};