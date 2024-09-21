class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            generateLexical(i,n,ans);
        }
        return ans;
    }

    private:
    void generateLexical(int cur,int limit,vector<int>&ans){
        if(cur>limit) return;

        ans.push_back(cur);
        for(int i=0;i<=9;i++){
            int next=cur*10+i;
            if(next<=limit){
                generateLexical(next,limit,ans);
            }else{
                break;
            }
        }
    }
};