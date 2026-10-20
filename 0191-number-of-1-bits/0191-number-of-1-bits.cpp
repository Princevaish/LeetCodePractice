class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        int temp=n;
        while(temp>0)
        {
            int digit=temp%2;
            ans=ans+digit;
            temp/=2;
        }
        return ans;
    }
};