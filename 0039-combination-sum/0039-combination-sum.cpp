class Solution {
public:
    
    void findSol(int ind,int target, vector<int> &ds,   vector<int> &candidates, int n , vector<vector<int>> &ans)
    {
        if(ind == n)
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            findSol(ind,target-candidates[ind],ds,candidates,n,ans);
            ds.pop_back();
        }
        findSol(ind+1,target,ds,candidates,n,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int >> ans;
        vector<int> ds;
        int n=candidates.size();
        findSol(0,target,ds,candidates,n,ans);
        return ans;
    }
};