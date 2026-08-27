class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mp;
        vector<vector<string>> result;

        for(string s: strs)
        {
            string sortedString=s;
            sort(sortedString.begin(),sortedString.end());
            mp[sortedString].push_back(s);
        }
        for(auto& pair : mp)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};