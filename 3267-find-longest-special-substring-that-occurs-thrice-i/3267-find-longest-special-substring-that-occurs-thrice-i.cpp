class Solution {
public:
    int maximumLength(string s) {
       
   
        map<string,int>mpp;
        for (int left = 0; left < s.size(); left++) {
            string curr;
            for (int right = left ; right < s.size(); right++) {
                if (curr.empty() or curr.back() == s[right]) {
                    curr.push_back(s[right]);
                    mpp[curr]++;
                }else{
                    break;
                }
            }
        }
        int ans=0;
        for(auto i:mpp){
            string str=i.first;
            if(i.second>=3 && str.length()>ans) ans=str.length();
        }
        if(ans==0) return -1;
        return ans;
        }
};