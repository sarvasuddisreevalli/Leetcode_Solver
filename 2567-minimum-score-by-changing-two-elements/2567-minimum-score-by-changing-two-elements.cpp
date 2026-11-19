class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return min(abs(nums[2]-nums.back()),min(abs(nums[0]-nums[nums.size()-3]),abs(nums[1]-nums[nums.size()-2])));
    }
};