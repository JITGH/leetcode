/*class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=0;
       // if(nums[0]==nums[1]){
         //   return -1;
        //}
       // else{
       // for(int i=0;i<nums.size();i++){
           int i=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]*nums[i]==nums[j]){
                    c++;
                
                  //break;
                }
              // i++; 
            }
            i++;
      //  }
      //  }
       if(c==0){
           return -1;
       }
       return c+1;
    }
};
*/
class Solution 
{
public:
    int longestSquareStreak(vector<int>& nums) 
    {  
        // sort(nums.begin(), nums.end(), greater<int>());
        
        // unordered_map<int, int> mp;
        // for(auto &it:nums)
        // {
        //     mp[it]++;
        // }
        
        // int count;
        // int maxi=1;
        
        // for(int i=0; i<nums.size()-1; i++)
        // {
        //     count=1;
        //     int x=nums[i];
        //     while(mp[sqrt(x)]>0)
        //     {
        //         int p=sqrt(x);
        //         //Since sqrt(x) can be a decimal number so we need to check  perfect square condition
        //         if(p*p==x) count++;
        //         else break;
        //         mp[sqrt(x)]--;
        //         x = sqrt(x);
        //     }
        //     maxi = max(maxi, count);
        // }
        // return maxi==1?-1:maxi;


        sort(nums.begin(),nums.end());
        set<int>process;
        int longeststreak=0;
        for(int current:nums){
            if(process.find(current)!=process.end())
            continue;

            int streak=current;
            int streaklen=1;
            while(true){
                if((long long)streak*(long long)streak>1e5) break;
                if(binarysearch(nums,streak*streak)){
                    streak*=streak;
                    process.insert(streak);
                    streaklen++;
                }else{
                    break;
                }
            }
            longeststreak=max(longeststreak,streaklen);
        }
        return longeststreak<2?-1:longeststreak;
    }


    private:
    bool binarysearch(vector<int>&nums,int target){
        if(target<0) return false;

        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]>target)
            right=mid-1;
            else
            left=mid+1;
        }
        return false;
    }
};