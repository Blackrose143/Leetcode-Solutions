class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<int> st;
        int val = 0;
        int n = s.size();

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                
                if(!st.empty() && st.top() == '(' && s[i] == ')'){
                    st.pop();
                    val++;

                } 
            }
        }

        return n - (2 * val);
        
    }
};

// 1 * 2 - n = bal

//n - 1 * 2 = bal

// "()))(("

