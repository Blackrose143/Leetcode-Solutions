class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length(), i = 0, ans = 0;

        stack<int> st;
        st.push(-1);
        for(char c:s) {
            if(c=='(')
                st.push(i);
            else {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    ans = max(ans,i-st.top());
            }
            i += 1;
        }
        return ans;
    }
};