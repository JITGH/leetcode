class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>pre(n);
        pre[0]=nums[0];
        int target=(1<<maximumBit)-1;
    //   // cout<<target<<" ";
    //     // for(int i=0;i<n;i++){
    //     //     xor1^=nums[i];
    //     // }
    //     int j=n-1;

    //     while(j>=0){
    //          int xor1=0;
    //         for(int i=0;i<=j;i++){
    //             xor1^=nums[i];
    //             //cout<<xor1<<" ";
    //         }
    //         for(int a=0;a<target;a++){
    //            // xor1^=a;
    //             if((xor1^a)==(target-1)){
    //                 ans.push_back(a);
    //                // xor1^=k;
    //                 break;
    //            }
            
    //         }
    //       //  xor1^=nums[j];
    //         j--;
    //     }

    //     return ans;

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^nums[i];
        }
        for(int i=0;i<n;i++){
            int curr=pre[n-i-1];
            ans[i]=curr^target;
        }

        return ans;
    }
};