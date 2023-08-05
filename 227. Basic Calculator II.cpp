class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';
        
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num =num *10  + (s[i] - '0');
            }
            
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {

                

                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int prev = st.top();
                    st.pop();
                    st.push(prev * num);
                } else if (op == '/') {
                    int prev = st.top();
                    st.pop();
                    st.push(prev / num);
                }
                
                num = 0;
                op = s[i];
            }
        }
        
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};
