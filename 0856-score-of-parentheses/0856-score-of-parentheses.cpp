class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt=0;
        stack<int> st;
        for(char c:s) {
            if(c=='(') {
                st.push(cnt);
                cnt=0;
            }else {
                cnt = st.top() + max(2*cnt,1);
                st.pop();
            }
        }
        return cnt;
    }
};