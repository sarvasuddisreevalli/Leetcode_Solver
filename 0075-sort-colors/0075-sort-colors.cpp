class Solution {
public:
    void sortColors(vector<int>& nums) {
    int cnt=0,cnt1=0,cnt2=0,numsSize=nums.size();
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0)cnt++;
        else  if(nums[i]==1)cnt1++;
        else cnt2++;
    }
    int k=0;
    while(cnt>0){
        nums[k++]=0;
        cnt--;
    }
    while(cnt1>0){
        nums[k++]=1;
        cnt1--;
    }
    while(cnt2>0){
        nums[k++]=2;
        cnt2--;
    }
}
};