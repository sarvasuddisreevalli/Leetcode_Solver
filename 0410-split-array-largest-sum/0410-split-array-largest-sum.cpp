class Solution {
public:
    bool is(int mid,int k,vector<int>&nums) {
        int sum=0,cnt=0;
        for(auto i : nums) {
            sum+=i;
            if(sum>mid) {
                sum=i;
                cnt++;
            }
        }
        if(sum) cnt++;
        return (cnt<=k) ;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end()),high=0;
        int ans=0;
        if(nums.size()==k) return low;
        for(int i=0;i<=nums.size()-k;i++) high+=nums[i];
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(is(mid,k,nums)) {
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};