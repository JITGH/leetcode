class Solution {
public:
    bool isvalid(vector<int>& a,int n,int d){
        int low=0;
        int high= a.size()-1;
       
        while(low<=high){
             int mid=low+(high-low)/2;
             if(abs(a[mid]-n)<=d){
                 return false;
             }
             else if(a[mid]<n){
                 low=mid+1;
             }
             else{
                 high=mid-1;
             }
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        //BRUTE FORCE APPROACH -> T.C. -> O(N*M)
        // for(int i=0;i<arr1.size();i++){
        //     bool flag=true;
        //     for(int j=0;j<arr2.size();j++){
                
        //         if(abs(arr1[i]-arr2[j])<=d ){
        //             flag=false;
        //         }
        //     }
        //     if(flag==true) ans++;
        // }
        //OPTIMAL IS BINARY SEARCH T.C->O(N LOG M)
        sort(arr2.begin(),arr2.end());
        for(int num:arr1){
            if(isvalid(arr2,num,d)){
                ans++;
            }
        }
        return ans;
    }
};