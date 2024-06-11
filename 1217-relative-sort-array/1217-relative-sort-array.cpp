class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mpp;
        vector<int>ans,rem;
        for(int i=0;i<arr2.size();i++){
            mpp[arr2[i]]=0;
        }
        for(int i=0;i<arr1.size();i++){
            if(mpp.find(arr1[i])!=mpp.end()){
            mpp[arr1[i]]++;
            }
            else{
                rem.push_back(arr1[i]);
            }
        }
        sort(rem.begin(),rem.end());
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<mpp[arr2[i]];j++){
                ans.push_back(arr2[i]);
            }
        }

         for (int i = 0; i < rem.size(); i++) {
            ans.push_back(rem[i]);
        }
        return ans;
    
    }
};