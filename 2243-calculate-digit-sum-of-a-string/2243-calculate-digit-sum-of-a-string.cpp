class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k) {
            string t="";
            int sum=0,l=0;
            for(int i=0;i<s.length();i++) {
                sum += s[i]-'0';
                l++;
                if(l==k || i==s.length()-1) {
                    l = 0;
                    t += to_string(sum);
                    sum = 0;
                }
            }
            s = t;
        }
        return s;
    }
};