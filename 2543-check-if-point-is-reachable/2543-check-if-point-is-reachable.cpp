class Solution {
public:
    int gcd(int a,int b) {
        if(a==0 || b==0) return a+b;
        if(a>b) return gcd(a%b,b);
        else return gcd(a,b%a);
    }
    bool isReachable(int targetX, int targetY) {
        int a=gcd(targetX,targetY);
        while(a>1){
            if(a%2!=0) return 0;
            else a=a/2;
        }
        if(a==1) return 1;
        return 0;
    }
};