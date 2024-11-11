class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>sieve(maxi+1,1);
        sieve[1]=0;
        for(int i=2;i<=sqrt(maxi+1);i++){
            if(sieve[i]==1){
                for(int j=i*i;j<=maxi;j+=i){
                    sieve[j]=0;
                }
            }
        }
        int currvalue = 1;
        int i = 0;
        while (i < nums.size()) {
            int difference=nums[i]-currvalue;
            if (difference < 0) {
                return 0;
            }
        if(sieve[difference]==1 || difference==0){
            i++;
            currvalue++;
        }else{
            currvalue++;
        }
        }
        return 1;
    }
};