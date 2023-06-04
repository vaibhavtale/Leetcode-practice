// TC = O(N)
// SC = O(N)

// To find at every Index chunks of water that can store at that Ind is Min(Greater left, Greater right)..
// this is pretty naive and intuitional if one has no greater on its left or right it cannot store any water.
// if height[i] is greater than Min(Greater left, Greater right) nothing can be store.

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> width(n, 0);
        int maxi = 0, maxi2 = 0;
        // stack<int> st, st2;

        for(int i=0; i<n; i++){

            // if(st.empty()){
            //     width[i] = 0;
            //     st.push(height[i]);
            // }
            // else if(st.top() >= height[i]){
            //     width[i] = st.top();
            // }
            // else if(st.top() < height[i]){
            //     width[i] = st.top();
            //     st.push(height[i]);
            // }

            width[i] = maxi;

            maxi = max(maxi, height[i]);
        }

        for(int i=n-1; i>=0; i--){

            // if(st2.empty()){
            //     width[i] = 0;
            //     st2.push(height[i]);
            // }
            // else if(st2.top() >= height[i]){
            //     width[i] = min(width[i], st2.top());
            // }
            // else if(st2.top() < height[i]){
            //     width[i] = 0;
            //     st2.push(height[i]);
            // }

            width[i] = min(width[i], maxi2);
            maxi2 = max(maxi2, height[i]);
        }

        int res = 0;

        for(int i=0; i<n; i++){

            if(width[i] - height[i] > 0) res += width[i] - height[i];
        }

        return res;
    }
};
