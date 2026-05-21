struct node{
    vector<node*> childs;
    node(){
        childs.resize(10);
    }
};

struct trie{
    node* root;
    trie(){
        root=new node();
    }

    void insert(string s){
        node* cur=root;
        for(char c:s){
            int id=c-'0';
            if(cur->childs[id]==nullptr)
                cur->childs[id]=new node();
            cur=cur->childs[id];
        }
    }

    int search(string s){
        node* cur=root;
        int cnt=0;
        for(char c:s){
            int id=c-'0';
            if(cur->childs[id]==nullptr)
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
        for(int i:arr1)
            t.insert(to_string(i));
        
        for(int i:arr2)
            ans=max(ans,t.search(to_string(i)));
        
        return ans;
    }
};