class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int m=target[0],cnt=m;
        for(int i=1;i<target.size();i++) {
            if(target[i]>m){
                cnt+=(target[i]-m);
            }
            m=target[i];
        }
        return cnt;//*max_element(target.begin(),target.end());
    }
};