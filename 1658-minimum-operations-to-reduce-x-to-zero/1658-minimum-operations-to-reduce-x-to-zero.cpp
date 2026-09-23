class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>s(n);
        map<int,int>m;
        int sum=0;
        for(int i=n-1;i>=0;i--) {
            sum+=nums[i];
            s[i]=sum;
            m[sum]=n-i;
        }
        int ans=INT_MAX;
        sum=0;
        for(int i=0;i<n;i++) {
            if(sum==x) ans=min(ans,i);
            if(m[x-sum]>0) ans=min(ans,i+m[x-sum]);
            sum+=nums[i];
            m[s[i]]=0;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};