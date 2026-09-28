class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        bool f=true;
        int cnt=0,ans=0;
        for(char c:s) {
            if(c=='(') {
                st.push(c);
                cnt++;
            }else if(c==')') {
                st.pop();
                cnt--;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};