class Solution {
public:
    int longestValidParentheses(string s) {
        deque<int> dq;

        int i=0,sol=0;
        dq.push_back(-1);
        for(char c:s) {
            if(c=='(') {
                dq.push_back(i);
            }else {
                dq.pop_back();
                if(dq.empty())
                    dq.push_back(i);
                else
                    sol = max(sol,i-dq.back());
            }
            i += 1;
        }
        return sol;
    }
};