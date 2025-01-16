class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorA=0;
        int xorB=0;
        if(nums2.size()%2!=0){
            for(int num:nums1){
                xorA^=num;
            }
        }

         if(nums1.size()%2!=0){
            for(int num:nums2){
                xorB^=num;
            }
        }

        return xorA^xorB;
    }
};