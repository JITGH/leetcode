class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int first=0;
        int second=n;
        int maxi=1001;

        for(int i=0;i<2*n;i++){
            if(i%2==0){
                nums[i]=(nums[first]%maxi)*maxi+nums[i];
                first++;
            }
            else{
                nums[i]=(nums[second]%maxi)*maxi+nums[i];
                second++;
            }
        }

        for(int i=0;i<2*n;i++){
            nums[i]/=maxi;

        }

        return nums;

    }
};