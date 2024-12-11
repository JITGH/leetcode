class Solution {
    private:
    bool valid(string s,string p){
        int n=s.size();
        int m=p.size();
        int i=0;
        int j=0;
        while(i<n){
            if(s[i] == p[j]) j++;
            else if(isupper(s[i])) return false;
            i++;
        }
        return j==m ?true:false;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        for(string s:queries){
            ans.push_back(valid(s,pattern));
        }
        return ans;
    }
};