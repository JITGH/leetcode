class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||numRows>=s.size()){
            return s;
        }
        // int ind=0;
        // int d=1;
        // vector<vector<char>>rows(numRows);
        // for(char c:s){
        //     rows[ind].push_back(c);
        //     if(ind==0){
        //         d=1;
        //     }if(ind==numRows-1){
        //         d=-1;
        //     }
        //     ind+=d;
        // }

        // string result;
        // for(const auto& row:rows){
        //     for(char c:row){
        //         result+=c;
        //     }
        // }

        // return result;


        string result="";
        int cycleLen=2*numRows-2;
        for(int i=0;i<numRows;i++){
            for(int j=0;j+i<s.size();j+=cycleLen){
                result+=s[j+i];

                if(i!=0 && i!=numRows-1 && j+cycleLen-i<s.size()){
                    result+=s[j+cycleLen-i];
                }
            }
        }
        return result;
    }
};