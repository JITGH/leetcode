class MyCalendarTwo {
    private:
    bool doesoverlap(int st1,int en1,int st2,int en2){
        return max(st1,st2)<min(en1,en2);
    }
    pair<int,int>getoverlap(int st1,int en1,int st2,int en2){
        return {max(st1,st2),min(en1,en2)};
    }
public:
    vector<pair<int,int>>bookings;
    vector<pair<int,int>>overlapBookings;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int,int>booking:overlapBookings){
            if(doesoverlap(booking.first,booking.second,start,end)){
                return false;
            }
        }

        for(pair<int,int>booking:bookings){
            if(doesoverlap(booking.first,booking.second,start,end)){
                overlapBookings.push_back(getoverlap(booking.first,booking.second,start,end));
            }
        }
        bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */