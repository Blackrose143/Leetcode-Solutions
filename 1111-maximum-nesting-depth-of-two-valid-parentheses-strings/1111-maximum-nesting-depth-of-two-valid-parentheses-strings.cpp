class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int cand=1;
        for(char c:seq) {
            if(c=='(')
                ans.push_back(1-cand);
            else
                ans.push_back(cand);
            cand ^= 1;
        }
        return ans;
    }
};