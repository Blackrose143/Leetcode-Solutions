class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;
        int ans=0;
        for(char c:word)
            st.insert(c);
        for(int i=0;i<word.length();i++){
            int c=word[i];
            if(c>='A' && c<='Z'){
                if(st.find(c+32)!=st.end()){
                    ans++;
                    st.erase(c);
                    st.erase(c+32);
                }
            }
            else{
                if(st.find(c-32)!=st.end()){
                    ans++;
                    st.erase(c);
                    st.erase(c-32);
                }
            }
        }
        return ans;
    }
};