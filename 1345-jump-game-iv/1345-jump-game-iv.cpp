class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++) m[arr[i]].push_back(i);
        vector<int>visited(arr.size(),0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        int cnt=0;
        while(!q.empty()) {
            int l=q.size();
            for(int i=0;i<l;i++) {
                int top=q.front();
                q.pop();
                if(top==arr.size()-1) return cnt;
                if(top>0 && visited[top-1]==0) {
                    q.push(top-1);
                    visited[top-1]=1;
                } 
                if(top<arr.size()-1 && visited[top+1]==0) {
                    q.push(top+1);
                    visited[top+1]=1;
                } 
                while(!m[arr[top]].empty()) {
                    if(visited[m[arr[top]].back()]==0) {
                        q.push(m[arr[top]].back());
                        visited[m[arr[top]].back()]=1;
                    }
                    m[arr[top]].pop_back();
                }
            }
            cnt++;
        }
        return 0;
    }
};