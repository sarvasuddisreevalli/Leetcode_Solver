class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++) {
            if(m[target-nums[i]]>0) return {i,m[target-nums[i]]-1};
            m[nums[i]]=i+1;
        }
        return {};
    }
};