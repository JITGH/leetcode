class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>>intervalsEnd;
        for(vector<int>interval:intervals){
            intervalsEnd.push_back({interval[0],1});
             intervalsEnd.push_back({interval[1]+1,-1});
        }

        sort(intervalsEnd.begin(),intervalsEnd.end());

        int concurentInterval=0;
        int maxconcurrentInterval=0;
        for(auto p:intervalsEnd){
            concurentInterval+=p.second;
            maxconcurrentInterval=max(maxconcurrentInterval,concurentInterval);
        }

           return  maxconcurrentInterval;
    }
 
};