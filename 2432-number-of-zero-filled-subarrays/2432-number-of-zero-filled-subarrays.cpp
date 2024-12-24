class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     bool iszerofilled=true;
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[j]!=0){
        //         break;
        //         }

        //         cnt++;
        //     }
        // }
        // return cnt;
        long long zerocnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zerocnt++;
                cnt+=zerocnt;
            }else{
                zerocnt=0;
            }
        }

        return cnt;
    }
};