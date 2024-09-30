class CustomStack {
    private:
//     vector<int>v;
// int top_ind;
list<int>stack;
int maxSize;
public:

    CustomStack(int maxSize) {
        // v.resize(maxSize);
        // top_ind=-1;
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        // if(top_ind<(int)(v.size())-1){
        //    v[++top_ind]=x;
        // }
        if(stack.size()<maxSize){
            stack.push_back(x);
        }
    }
    
    int pop() {
        // if(top_ind>-1){
        //     return v[top_ind--];
        // }else{
        //     return -1;
        // }
        if(stack.empty()) return -1;
        int topelement=stack.back();
        stack.pop_back();
        return topelement;
    }
    
    void increment(int k, int val) {
        // int limit=min(k,top_ind+1);
        // for(int i=0;i<limit;i++){
        //     v[i]+=val;
        // }
        auto it=stack.begin();
        for(int i=0;i<k && it!=stack.end();i++,it++){
            *it+=val;
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