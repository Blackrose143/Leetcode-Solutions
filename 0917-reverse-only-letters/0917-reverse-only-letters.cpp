class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int l=0,h=n-1;
        while(l<h) {
            while(l<n && !((s[l]>='a' && s[l]<='z')||(s[l]>='A' && s[l]<='Z')))
                l++;

            while(h>=0 && !((s[h]>='a' && s[h]<='z') || (s[h]>='A' && s[h]<='Z')))
                h--;

            if(l<h)
                swap(s[l],s[h]);
            l++;
            h--;
        }
        return s;
    }
};