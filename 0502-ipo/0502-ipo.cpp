class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>>q;
        for(int i=0;i<profits.size();i++) q.push({-capital[i],profits[i]});
        priority_queue<int>q1;
        while(k>0) {
            while(!q.empty() && (-q.top().first)<=w) {
                q1.push(q.top().second);
                q.pop();
            }
            if(q1.empty()) break;
            w+=q1.top();
            q1.pop();
            k--;
        }
        return w;
    }
};