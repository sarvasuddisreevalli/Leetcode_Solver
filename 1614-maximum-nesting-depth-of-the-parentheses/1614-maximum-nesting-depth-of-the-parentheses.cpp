class Solution {
public:
    int maxDepth(string s) {
        int maxi=0,bf=0;
        for(char i : s) {
            if(i=='(') bf++;
            else if(i==')') bf--;
            maxi=max(maxi,bf);
        }
        return maxi;
    }
};