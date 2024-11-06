class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>values=nums;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n-1;j++){
        //         if(values[j]<=values[j+1]){
        //             continue;
        //         }else{
        //             if(__builtin_popcount(nums[j])==__builtin_popcount(nums[j+1])){
        //                 swap(values[j],values[j+1]);
        //             }else{
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // return true;

        // int numofset=__builtin_popcount(values[0]);
        // int maxofseg=values[0];
        // int minofseg=values[0];


        // int maxprevseg=INT_MIN;
        // for(int i=1;i<n;i++){
        //     if(__builtin_popcount(values[i])==numofset){
        //         maxofseg=max(maxofseg,values[i]);
        //         minofseg=min(minofseg,values[i]);
        //     }else{
        //         if(minofseg<maxprevseg){
        //             return false;
        //         }
        //         maxprevseg=maxofseg;

        //         maxofseg=values[i];
        //         minofseg=values[i];
        //         numofset=__builtin_popcount(values[i]);
        //     }
        // }
        // if(minofseg<maxprevseg){
        //     return false;
        // }
        // return true;


        for(int i=0;i<n-1;i++){
            if(values[i]<=values[i+1]){
                continue;
            }else{
                if(__builtin_popcount(values[i])==__builtin_popcount(values[i+1])){
                    swap(values[i],values[i+1]);
                }else{
                    return false;
                }
            }
        }

        for(int i=n-1;i>=1;i--){
            if(values[i]>=values[i-1]){
                continue;
            }else{
                if(__builtin_popcount(values[i])==__builtin_popcount(values[i-1])){
                    swap(values[i],values[i-1]);
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};