class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q;
        unordered_set<int>visited,myboxes,inqueue;
        for(auto i : initialBoxes) {
            if(status[i]==1 && inqueue.count(i)==0) {
                inqueue.insert(i);
                q.push(i);
            }
            myboxes.insert(i);
        }
        int sum=0;
        while(!q.empty()) {
            int temp=q.front();
            q.pop();
            sum+=candies[temp];
            visited.insert(temp);
            for(auto i : keys[temp]) status[i]=1;
            for(auto i : containedBoxes[temp]) myboxes.insert(i);
            for(auto i : containedBoxes[temp]) {
                if(visited.count(i)==0 && status[i]==1 && inqueue.count(i)==0){
                    q.push(i);
                    inqueue.insert(i);
                }
            }
            for(auto i : keys[temp]) {
                if(visited.count(i)==0 && myboxes.count(i)==1 && inqueue.count(i)==0) {
                    q.push(i);
                    inqueue.insert(i);
                }
            }
        }
        return sum;
    }
};