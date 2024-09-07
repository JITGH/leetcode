class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==1 && citations[0]>0) return 1;
        sort(citations.begin(),citations.end());

        int size=citations.size();
        // int maxi=0;
        // for(int i=0;i<size;i++){
        //     if(citations[i]>=size-i){
        //         maxi=max(maxi,size-i);
        //     }
        // }

        // return maxi;

        int start=0;
        int end=size-1;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(citations[mid]>=size-mid){
                ans=max(ans,size-mid);
                end=mid-1;

            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};