class Solution {
public:
    int countOrders(int n) {
        long long ans=1;
        for(int i=2;i<=n;i++) {
            ans%=(1000000007);
            int a=(2*i)-1;
            ans*=(a*(a+1))/2;
            ans%=(1000000007);
        }
        return (int) ans;
    }
};