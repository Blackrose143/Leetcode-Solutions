class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        int n=s.length();

        if(n%2!=0)
            return false;

        int mi_open=0;
        int mx_open=0;
        for(int i=0;i<n;i++) {
            if(locked[i]=='0') {
                mi_open--;
                mx_open++;
            }else{
                if(s[i]=='(') {
                    mi_open++;
                    mx_open++;
                }else{
                    mi_open--;
                    mx_open--;
                }
            }

            if(mx_open<0)
                return false;
            if(mi_open<0)
                mi_open=0;
        }
        return mi_open==0;
    }
};