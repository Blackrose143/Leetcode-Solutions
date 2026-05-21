struct node{
    vector<bool> s1;
    vector<bool> s2;
    vector<node*> childs;
    node(){
        childs.resize(26);
        s1.resize(26);
        s2.resize(26);
    }
};

struct trie{
    node* root;
    trie(){
        root=new node();
    }

    void insert(string& s,bool b){
        node* cur=root;
        for(char c:s){
            int id=c-'0';
            if(cur->childs[id]==nullptr)
                cur->childs[id]=new node();
            if(b)
                cur->s1[id]=1;
            else
                cur->s2[id]=1;
            cur=cur->childs[id];
        }
    }

    int search(string& s){
        node* cur=root;
        int cnt=0;
        for(char c:s){
            int id=c-'0';
            if(cur->childs[id]==nullptr || !cur->s1[id] || !cur->s2[id])
                return cnt;
            cur=cur->childs[id];
            cnt+=1;
        }
        return cnt;
    }

};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie t;
        t=trie();
        int ans=0;
        for(int i:arr1){
            string s=to_string(i);
            t.insert(s,true);
        }
        for(int i:arr2){
            string s=to_string(i);
            t.insert(s,false);
        }
        for(int i:arr1){
            string s=to_string(i);
            ans=max(ans,t.search(s));
        }
        for(int i:arr2){
            string s=to_string(i);
            ans=max(ans,t.search(s));
        }
        return ans;
    }
};