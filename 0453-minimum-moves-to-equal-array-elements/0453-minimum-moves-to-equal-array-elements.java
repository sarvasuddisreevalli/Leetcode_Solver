class Solution {
    public int minMoves(int[] nums) {
        int cnt=0;
        int mini=1000000000;
        for(int i=0;i<nums.length;i++) if(nums[i]<mini) mini=nums[i];
        for(int i=0;i<nums.length;i++) cnt+=nums[i]-mini;
        return cnt;
    }
}