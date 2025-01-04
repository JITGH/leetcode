class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // int n = nums.size(), steps = 0;
        // sort(nums.begin(), nums.end());
        // int median = nums[n/2]; // Finding median
        // for(int i=0; i<n; i++){
        //     steps += abs(nums[i] - median); //Adding absolute difference
        // }
        // return steps;

         sort(nums.begin(),nums.end());
        int n=nums.size();
        int moves=0;
        int med;
        if(n%2!=0){
          med=(n-1)/2;
          for(int i=0;i<n;i++){
            moves+=abs(nums[med]-nums[i]);
          }
        }
        else{
            med=n/2;
            for(int i=0;i<n;i++){
                moves+=abs(nums[med]-nums[i]);
            }
        }
        return moves;
    }
};