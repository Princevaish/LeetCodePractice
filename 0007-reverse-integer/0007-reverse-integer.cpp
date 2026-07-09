class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        int unsigned temp=x;
        long long num=0;
        if(x<0) temp=-(long long)x;
        while(temp>0)
        {
            int unsigned digit=temp%10;
            num=num*10+digit;
            if(num > INT_MAX) return 0;
            temp/=10;
        }
        if(x>0)
        {
            return num;
        }
        else
        {
            if(-num<INT_MIN) return 0;
            return -num;
        }
        
    }
};