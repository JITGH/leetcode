class MyCircularQueue {
    private:
    vector<int>v;
    int st=0;
    int len=0;
public:
    MyCircularQueue(int k) {
        v.resize(k);
        
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        v[(st+len++)%v.size()]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        st=(st+1)%v.size();
        --len;
        return true;
    }
    
    int Front() {
         if(isEmpty()) return -1;
         return v[st];
    }
    
    int Rear() {
         if(isEmpty()) return -1;
         return v[(st+len-1)%v.size()];
    }
    
    bool isEmpty() {
        return !len;
    }
    
    bool isFull() {
        return len==v.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */