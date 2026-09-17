class Solution {
public:
    int finde1(vector<int>& nums,int i,int j,int target) {
        int ans=j;
        while(i<=j) {
            int mid=i+(j-i)/2;
            if(nums[mid]==target) {
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
    int finde2(vector<int>& nums,int i,int j,int target) {
        int ans=i;
        while(i<=j) {
            int mid=i+(j-i)/2;
            if(nums[mid]==target) {
                ans=mid;
                i=mid+1;
            }
            else j=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int i=0,j=nums.size()-1;
        while(i<=j) {
            int mid=i+(j-i)/2;
            if(nums[mid]==target) {
                ans[0]=mid;
                ans[1]=mid;
                ans[0]=finde1(nums,i,mid,target);
                ans[1]=finde2(nums,mid,j,target);
                return ans;
            }
            else if(nums[mid]<target) i=mid+1;
            else j=mid-1;
        }
        return ans;
    }
};