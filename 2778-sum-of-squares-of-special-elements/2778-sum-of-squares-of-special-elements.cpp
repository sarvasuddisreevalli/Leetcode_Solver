class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<=nums.size();i++) {
            if(nums.size()%i==0) ans+=pow(nums[i-1],2);
        }
        return ans;
    }
};