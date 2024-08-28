class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
       part(0,path,ans,s);

        return ans;
    }
    void part(int ind,vector<string>&path,vector<vector<string>>&ans,string s){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                part(i+1,path,ans,s);
                path.pop_back();
            }
        }
    }

        bool ispalindrome(string s,int st,int end){
            while(st<=end){
                if(s[st++]!=s[end--]){
                    return false;
                }
                
            }
            return true;
        }
    
    
};