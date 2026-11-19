class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int a=nums[0]-nums[nums.size()-3];
        int b=nums[2]-nums[nums.size()-1];
        int c=nums[1]-nums[nums.size()-2];
        return min(a,min(b,c));
    }
};