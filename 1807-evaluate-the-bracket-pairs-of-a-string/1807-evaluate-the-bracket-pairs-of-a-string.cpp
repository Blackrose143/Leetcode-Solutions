class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        stack<int> st;
        unordered_map<string,string> mp;
        for(auto vc:knowledge) 
            mp[vc[0]] = vc[1];

        for(char c:s) {
            if(c==')') {
                string cur="";
                while(st.top()!='(') {
                    cur += st.top();
                    st.pop();
                }
                st.pop();
                reverse(cur.begin(),cur.end());
                if(mp.find(cur)!=mp.end()) {
                    string s1=mp[cur];
                    for(int i=0;i<s1.size();i++)
                        st.push(s1[i]);
                }else
                    st.push('?');
            }else
                st.push(c);
        }

        string ans="";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};