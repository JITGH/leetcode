class Solution {
   /* private:
    void swapif(vector<int>& nums1, vector<int>& nums2, int ind1,int ind2){
        if(nums1[ind1]>nums2[ind2]){
            swap(nums1[ind1],nums2[ind2]);
        }
    }*/
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //   for(int i=0;i<n;i++){
    //        nums1[m+i]= nums2[i];
    //    }
    //    sort(nums1.begin(),nums1.end());

    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(j>=0){
        if(i>=0 && nums1[i]>nums2[j]){
            nums1[k--]=nums1[i--];
        }else{
            nums1[k--]=nums2[j--];
        }
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
   
    }
};