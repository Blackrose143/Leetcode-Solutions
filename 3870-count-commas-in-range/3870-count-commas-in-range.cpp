class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        if(s.length()<4)
            return 0;
        int val = stoi(s);
        return val-999;
    }
};