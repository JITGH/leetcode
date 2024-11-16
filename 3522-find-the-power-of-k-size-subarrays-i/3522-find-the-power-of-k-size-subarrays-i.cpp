class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        int n=a.size();
        vector<int>ans(n-k+1);
       
        for(int i=0;i<=n-k;i++){
             bool issort=true;
            for(int j=i;j<i+k-1;j++){
                if(a[j+1]!=a[j]+1){
                    issort=false;
                    break;
                }
            }
           if(issort){
            ans[i]=a[i+k-1];
           }else{
            ans[i]=-1;
           }
        }

        return ans;
    }
};