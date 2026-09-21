class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1) {
            if(k%2==0) return nums[0];
            return -1;
        }
        int maxi=-1;
        for(int i=0;i<k-1 && i<nums.size(); i++) maxi=max(maxi,nums[i]);
        if(nums.size()>k) return max(maxi,nums[k]);
        return maxi;
    }
};