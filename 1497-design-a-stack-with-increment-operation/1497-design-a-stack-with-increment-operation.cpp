class CustomStack {
    private:
    vector<int>v;
int top_ind;
public:

    CustomStack(int maxSize) {
        v.resize(maxSize);
        top_ind=-1;
    }
    
    void push(int x) {
        if(top_ind<(int)(v.size())-1){
           v[++top_ind]=x;
        }
    }
    
    int pop() {
        if(top_ind>-1){
            return v[top_ind--];
        }else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        int limit=min(k,top_ind+1);
        for(int i=0;i<limit;i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */