class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        if(k==1) return a;
	    stack<pair<int,int>>in,out;
	    vector<int>ans;
	    for(int i=0;i<n;i++) {
	        //pop logic
	        if(i>=k) {
	            if(out.empty()) {
	                while(!in.empty()) {
	                    if(out.empty()) out.push({in.top().first,in.top().first});
	                    else out.push({in.top().first,max(in.top().first,out.top().second)});
	                    in.pop();
	                }
	            }
	            out.pop();
	        }
	        //push logic
	        if(in.empty()) in.push({a[i],a[i]});
	        else in.push({a[i],max(a[i],in.top().second)});
	    
	        if(i>=(k-1)) {
	            if(in.empty()) ans.push_back(out.top().second);
	            else if(out.empty()) ans.push_back(in.top().second);
	            else ans.push_back(max(in.top().second,out.top().second));
	        }
	    }
        return ans;
    }
};