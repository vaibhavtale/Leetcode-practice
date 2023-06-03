// TC - O(N)
// SC = O(N).

class Solution {
public:
    string decodeString(string s) {
        stack<int> st; // Stack to store the repeat count of each substring
        stack<string> res; // Stack to store intermediate results
        int num = 0; // Variable to store the current repeat count

        for(int i=0; i<s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '['){
                st.push(num);
                num = 0;
            }
        }

        string str = "";

        for(int i=s.length()-1; i>=0; i--){
            if(s[i] >= 'a' && s[i] <= 'z'){
                str = s[i] + str;
            }
            else if(s[i] == ']') {
                if(str.length()) res.push(str); // Add non-empty substring to the stack
                res.push("]"); // Push "]" marker to the stack
                str = "";
            }
            else if(s[i] == '['){
                while(!res.empty()){
                    if(res.top() == "]"){
                        res.pop(); // Remove the "]" marker
                        break;
                    }
                    str += res.top(); // Append the substring to the current result
                    res.pop();
                }

                int num = st.top(); st.pop(); // Get the repeat count
                string tt = "";

                while(num--) tt += str; // Repeat the substring

                str = tt; // Update the current substring
            }
        }

        while(!res.empty()){
            if(res.top() != "]") str += res.top(); // Add non-empty substring to the result
            res.pop();
        }

        return str;
    }
};
