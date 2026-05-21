class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st;
        for(int num:arr1){
            string s=to_string(num);
            for(int i=1;i<=s.length();i++)
                st.insert(s.substr(0,i));
        }
        
        int ans=0;
        for(int i:arr2){
            string s=to_string(i);
            int len=0;
            for(int j=1;j<=s.length();j++){
                cout << s.substr(0,j) << ' ';
                if(st.find(s.substr(0,j))==st.end())
                    break;
                len=j;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};