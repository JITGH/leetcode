class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x=0;
        int y=0;
 for (string command : commands) {
       if(command=="UP"){
        x--;
       }else if(command=="DOWN"){
        x++;
       }else if(command=="RIGHT"){
        y++;
       }else if(command=="LEFT"){
        y--;
       }
}
       return x*n+y;
    }
};