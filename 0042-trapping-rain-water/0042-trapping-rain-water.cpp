class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefix(height.size(),0);
        vector<int>suffix(height.size(),0);
        int maxi=0;
        for(int i=0;i<height.size();i++) {
            prefix[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        maxi=0;
        for(int i=height.size()-1;i>=0;i--) {
            suffix[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++) {
            int water=min(prefix[i],suffix[i]);
            if(water>height[i]) ans+=water-height[i];
        }
        return ans;
    }
};