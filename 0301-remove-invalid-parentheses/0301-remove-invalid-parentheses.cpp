class Solution {
public:

    int n,mx=0;
    unordered_set<string> res;
    void fun(int i,string& s,string& t,int cnt) {

        if(cnt<0)
            return ;
        
        if(i>=n) {
            if(cnt==0) {
                res.insert(t);
            }
            return ;
        }

        char c=s[i];
        int nc = cnt;
        if(c=='(')
            nc++;
        else if(c==')')
            nc--;

        t.push_back(c);
        fun(i+1,s,t,nc);
        t.pop_back();

        fun(i+1,s,t,cnt);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        string t="";
        fun(0,s,t,0);

        vector<string> ans;
        int m =0;
        for(string x:res)
            m = max(m,(int)x.size());
        for(string x:res)
            if(x.size()==m)
                ans.push_back(x);
        return ans;
    }
};