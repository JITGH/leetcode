class Solution {
public:
void findcomb(int ind,int target,vector<int>& arr,vector<vector<int>>&ans,vector<int>&ds){
    
        if(target==0){
            ans.push_back(ds);
            return;
        }
      //  return;
    
   /* if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        findcomb(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();

    }*/
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
         findcomb(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();

    }
   // findcomb(ind+1,target,arr,ans,ds);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort (candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findcomb(0,target,candidates,ans,ds);
        return ans;
    }
};