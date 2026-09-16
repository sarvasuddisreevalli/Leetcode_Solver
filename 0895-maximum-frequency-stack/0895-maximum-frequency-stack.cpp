// class compare {
// public:
//     bool operator()(pair<int,int>&a, pair<int,int>&b)
//     {
//         return a.first < b.first;
//     }
// };

class FreqStack {
public:
    priority_queue<vector<int>>q;
    map<int,int>m;
    int k=0;

    FreqStack() {
    }
    
    void push(int val) {
        m[val]++;
        q.push({m[val],k++,val});
    }
    
    int pop() {
        int tops=q.top()[2];
        m[tops]--;
        q.pop();
        return tops;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */