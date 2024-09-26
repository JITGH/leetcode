class MyCalendar {
public:
     vector<pair<int,int>>ans;
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        for(const auto[s,e]:ans){
            if(start<e && end>s){
                return false;
            }
        }
        ans.emplace_back(start,end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */