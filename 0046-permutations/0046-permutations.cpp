class Solution {
public:
// void f(vector<vector<int>>&ans,vector<int>&ds,int freq[],vector<int>&nums){
//     if(ds.size()==nums.size()){
//         ans.push_back(ds);
//         return;
//     }

//     for(int i=0;i<nums.size();i++){
//         if(!freq[i]){
//             ds.push_back(nums[i]);
//             freq[i]=1;
//             f(ans,ds,freq,nums);
//             freq[i]=0;
//             ds.pop_back();
//         }
//     }
// }

    void f(int ind,vector<vector<int>>&ans,vector<int>&nums){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            f(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }

        
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
       // vector<int>ds;
        //int freq[nums.size()+1];
        //for(int i=0;i<=nums.size();i++) freq[i]=0;

        //f(ans,ds,freq,nums);

        f(0,ans,nums);

        return ans;
    }
};