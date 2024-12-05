class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char,int>>sq,tq;
        for(int i=0;i<start.size();i++){
            if(start[i]!='_'){
                sq.push({start[i],i});
            }
        }

        for(int i=0;i<target.size();i++){
            if(target[i]!='_'){
                tq.push({target[i],i});
            }
        }

        if(sq.size()!=tq.size()) return false;
        while(!sq.empty()){
            auto it=sq.front();
            sq.pop();
            auto ti=tq.front();
            tq.pop();
//check if character match and movement rule
            if(it.first!=ti.first||(it.first=='L' && it.second<ti.second)||
            (it.first=='R' && it.second>ti.second)){
                return false;
            }
        }
        return true;
    }
};