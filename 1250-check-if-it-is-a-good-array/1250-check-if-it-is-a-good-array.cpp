class Solution {
public:
    int gcd(int a,int b) {
        if(a==0 || b==0) return a+b;
        return gcd(b,a%b);
    }
    bool isGoodArray(vector<int>& nums) {
        int k=nums[0];
        for(int i=0;i<nums.size();i++) {
           k=gcd(nums[i],k);
           if(k==1) return 1;
        }
        return 0; 
    }
};