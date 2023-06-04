//TC = O(1)
//Sc = O(N)

// Hint keep the track of corresponding minimum element while pushing in stack.

class MinStack {
public:

    stack<pair<int,int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.empty()) st.push({val, val});

        else{

            if(st.top().first < val) st.push({st.top().first, val});

            else st.push({val, val});
        }
    }
    
    void pop() {
        
        st.pop();
    }
    
    int top() {
        
        return st.top().second;
    }
    
    int getMin() {
        
        return st.top().first;
    }
};
