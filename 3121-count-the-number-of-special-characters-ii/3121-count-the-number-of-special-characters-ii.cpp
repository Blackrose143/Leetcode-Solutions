class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size(),ans=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z')
                mp[word[i]]=i;
            else if(mp.find(word[i])==mp.end())
                    mp[word[i]]=i;
        }
        for(auto i:mp){
            char c=i.first;
            int s=i.second;
            if(c>='a' && c<='z'){
                if(mp.find(c-32)!=mp.end()){
                    if(mp[c]<mp[c-32])
                        ans++;
                }
            }
        }
        return ans;
    }
};