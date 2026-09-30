class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int dep=0;
        for(char c:seq) {
            if(c=='(') {
                ans.push_back(dep%2);
                dep++;
            }else{
                dep--;
                ans.push_back(dep%2);
            }
        }
        return ans;
    }
};