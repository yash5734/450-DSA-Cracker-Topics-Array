class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            
            int c = s[i];
            if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
            {
                st.push(c);
            }
            
            else{
                
                if(c == ')'){
                    bool isRedundant = true;
                    while(st.top() != '('){
                        
                        if(st.top()== '+' || st.top()== '-' || st.top()== '*' || st.top()== '/'){
                            isRedundant = false;
                        }
                        st.pop();
                    }
                    
                    if(isRedundant==true){
                      return 1;
                    }
                    st.pop();
                }
                
            }
            
           
        }
         return 0;
    }
};
