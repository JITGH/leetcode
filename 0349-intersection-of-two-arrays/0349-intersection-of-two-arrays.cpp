class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int l1=nums1.size(),l2=nums2.size();
        vector<int> ans;
        
            int arr[1001]={-1};
            for(int i=0;i<l1;i++){
                arr[nums1[i]]=1;
            }
            for(int i=0;i<l2;i++){
                //if element is present in array1 push to ans and make it -1 
                if(arr[nums2[i]]==1) {
                    ans.push_back(nums2[i]); 
                    arr[nums2[i]]=-1;
                }
            }
            return ans;
    
      /*  vector<int>intersection;
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums2[j]<nums1[i]){
                j++;
            }
            else{
                if(intersection.size()==0||intersection.back()!=nums1[i]||intersection.back()!=nums2[j]){
                intersection.push_back(nums1[i]);
                i++;
                j++;
            }
            }
        }
        return intersection;
        */
    }
};