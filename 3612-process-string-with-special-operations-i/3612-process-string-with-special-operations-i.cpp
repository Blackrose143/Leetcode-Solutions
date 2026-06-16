class Solution {
public:
    string processStr(string s) {
        string res="";
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c>='a' && c<='z')
                res+=c;
            else if(c=='*'){
                if(res.length()!=0)
                    res.pop_back();
            }else if(c=='#')
                res=res+res;
            else if(c=='%')
                reverse(res.begin(),res.end());
        }
        return res;
    }
};