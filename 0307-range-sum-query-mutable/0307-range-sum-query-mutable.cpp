struct node{
    int summ;
    node(){
        summ = 0;
    }
    node(int val){
        summ = val;
    }
};

    node merge(node a,node b){
        node c;
        c.summ = a.summ + b.summ;
        return c;
    }

    struct segTree{

        int sz;
        vector<node> tree;

        void init(int n){
            sz = 1;
            while(sz<n)
                sz *= 2;
            tree.resize(sz*2);
        }

        void build(vector<int>& nums){
            build(0,sz,0,nums);
        }

        void build(int lx,int rx,int x,vector<int>& nums){
            if(rx-lx==1){
                if(lx<nums.size())
                    tree[x] = node(nums[lx]);
                return ;
            }
            int mi = (rx-lx)/2+lx;
            build(lx,mi,x*2+1,nums);
            build(mi,rx,x*2+2,nums);
            tree[x] = merge(tree[x*2+1],tree[x*2+2]);
        }

        void pointupdate(int ix,int val){
            pointupdate(0,sz,0,ix,val);
        }

        void pointupdate(int lx,int rx,int x,int ix,int val){
            if(rx-lx==1){
                tree[x] = node(val);
                return ;
            }
            int mi = (rx-lx)/2+lx;
            if(ix<mi)
                pointupdate(lx,mi,x*2+1,ix,val);
            else
                pointupdate(mi,rx,x*2+2,ix,val);
            tree[x] = merge(tree[x*2+1],tree[x*2+2]);
        }

        node rangeQuery(int l,int r){
            return rangeQuery(0,sz,0,l,r+1);
        }

        node rangeQuery(int lx,int rx,int x,int l,int r){
            if(rx<=l || lx>=r)
                return node();
            if(lx>=l && rx<=r)
                return tree[x];
            int mi = (rx-lx)/2+lx;
            node lq = rangeQuery(lx,mi,x*2+1,l,r);
            node rq = rangeQuery(mi,rx,x*2+2,l,r);
            return merge(lq,rq);
        }
    }sg;

class NumArray {
public:

    NumArray(vector<int>& nums) {
        sg.init(nums.size());
        sg.build(nums);
    }
    
    void update(int index, int val) {
        sg.pointupdate(index,val);
    }
    
    int sumRange(int left, int right) {
        return sg.rangeQuery(left,right).summ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */