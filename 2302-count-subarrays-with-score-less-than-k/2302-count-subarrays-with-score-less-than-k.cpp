class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector<long long>ans(nums.size(),0);
        long long i=0,j=0,cnt=0;
        while(j<nums.size()) {
            cnt+=nums[j];
            if((cnt)*(j-i+1)<k) j++;
            else if(i<j){
                ans[i]=(j-i);
                cnt-=nums[i++];
                cnt-=nums[j];
            }
            else {
                cnt=0;
                ans[i++]=0;
                j++;
            }
        }

        while(i<j) {
            ans[i]=(j-i);
            i++;
        }
        long long sum=0;
        for(auto i : ans) {
            sum+=i;
            cout<<i<<' ';
        }
        return sum;
    }
};