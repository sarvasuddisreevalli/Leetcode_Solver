class Solution {
    public int maxDepth(String s) {
        int ans=0,bf=0;
        for(int i=0;i<s.length();i++) {
            char ch=s.charAt(i);
            if(ch=='(') bf++;
            else if(ch==')') bf--;
            if(bf>ans) ans=bf;
        }
        return ans;
    }
}