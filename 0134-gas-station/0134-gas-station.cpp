class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_Gas=0;
        int total_Cost=0;
        int curr_Gas=0,starting_Point=0;

        for(int i=0;i<n;i++){
            total_Gas+=gas[i];
            total_Cost+=cost[i];

            curr_Gas+=gas[i]-cost[i];
            if(curr_Gas<0){
                starting_Point=i+1;
                curr_Gas=0;
            }
        }
        return (total_Gas<total_Cost)?-1:starting_Point;
    }
};