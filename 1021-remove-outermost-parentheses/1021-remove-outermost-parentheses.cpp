class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans="",cur="";
        for(char c:s) {

            if(c=='(')
                cnt++;
            else
                cnt--;

            if(cnt>=1) {
                if(cnt>1 || c!='(')
                    cur += c;
            }
        
            if(cnt==0) {
                ans += cur;
                cur = "";
            }
        }
        return ans;
    }
};