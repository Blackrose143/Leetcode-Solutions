class Solution {
public:
    bool checkString(string s) {
        bool f = false;
        for(char c:s) {
            if(c=='a') {
                if(f)
                    return false;
            }else
                f = true;
        }
        return true;
    }
};