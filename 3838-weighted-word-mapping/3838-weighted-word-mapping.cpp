class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto word:words){
            int tot=0;
            for(int c:word)
                tot+=weights[c-'a'];
            ans+='z'-(tot%26);
        }
        return ans;
    }
};