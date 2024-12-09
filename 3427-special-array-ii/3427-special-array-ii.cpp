class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& queries) {
        int n=a.size();
        int m=queries.size();
        int t=queries[0].size();
        vector<bool>ans(m,false);
        vector<int>pre(n,0);
        pre[0]=0;
        for(int i=1;i<n;i++){
            if(a[i]%2==a[i-1]%2){
                pre[i]=pre[i-1]+1;
            }else{
                pre[i]=pre[i-1];
            }
        }

        for(int i=0;i<m;i++){
            vector<int>query=queries[i];
            int st=query[0];
            int en=query[1];
            ans[i]=pre[en]-pre[st]==0;
        }
        // vector<int>vio;
        // for(int i=1;i<n;i++){
        //     if(a[i]%2==a[i-1]%2){
        //         vio.push_back(i);
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     vector<int>querie=queries[i];
        //     int from=querie[0];
        //     int to=querie[1];
            
        //     bool found=binarysearch(from+1,to,vio);
        //     if(found){
        //         ans[i]=false;
        //     }else{
        //       ans[i]=true;
        //     }
        // }
         return ans;
    }

    // private:
    // bool binarysearch(int st,int en,vector<int>&vio){
    //     int left=0;
    //     int right=vio.size()-1;
    //     while(left<=right){
    //         int mid=left+(right-left)/2;
    //         int vin=vio[mid];

    //         if(vin<st){
    //             left=mid+1;
    //         }else if(vin>en){
    //             right=mid-1;
    //         }else{
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};