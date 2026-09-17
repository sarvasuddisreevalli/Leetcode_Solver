class Solution {
public:
    int GCD(int a,int b) {
        if(a==0 || b==0) return a+b;
        else if(a>b) return GCD(a%b,b);
        else return GCD(a,b%a);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int gcd=0;
        for(auto i : numsDivide){
            gcd=GCD(gcd,i);
        }
        int i=0;
        while(i<nums.size()) {
            if(gcd%nums[i]==0) return i;
            else{
                int temp=nums[i];
                while(i<nums.size() && nums[i]==temp) {
                    i++;
                }
            }
        }
        return -1;
    }
};