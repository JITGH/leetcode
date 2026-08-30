class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int min_ind=-1;
        int maxi=INT_MIN;
        int max_ind=-1;

        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                max_ind=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                min_ind=i;
            }
        }

        int from_front=max(min_ind,max_ind)+1;
        int from_back=n-min(min_ind,max_ind);
        int both_side=(min(max_ind,min_ind)+1)+(n-max(min_ind,max_ind));

        return min(from_front,min(from_back,both_side));


    }
};