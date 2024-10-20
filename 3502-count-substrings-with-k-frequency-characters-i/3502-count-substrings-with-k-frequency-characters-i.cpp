class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        int c=0;
        
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;

                //if(mpp.find(s[j])!=mpp.end()){
                    for(auto it:mpp){
                        if(it.second>=k){c++;
                       // continue;
                       break;
                        }
                   // }
                   
                }
            }
        }
        return c;
    }
};