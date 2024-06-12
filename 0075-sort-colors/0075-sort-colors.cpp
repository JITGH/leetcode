class Solution {
public:
    void sortColors(vector<int>& nums) {
    /*    int i,c0=0,c1=0,c2=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                c0++;
            }
            if(nums[i]==1){
                c1++;
            }
            if(nums[i]==2){
                c2++;
            }
        }
        for(i=0;i<c0;i++){
            nums[i]=0;
        }
        for(i=c0;i<c0+c1;i++){
            nums[i]=1;
        }
        for(i=c0+c1;i<nums.size();i++){
            nums[i]=2;
        }
        */
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};