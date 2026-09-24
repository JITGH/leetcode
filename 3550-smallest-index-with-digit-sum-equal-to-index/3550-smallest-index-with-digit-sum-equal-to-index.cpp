class Solution {
public:
    int isequalsum(int num){
        if(num<10) return num;
        int check=num;
        int sum=0;
        while(check>0){
            int r=check%10;
            sum+=r;
            check/=10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(isequalsum(nums[i])==i) return i;
        }

        return -1;
    }
};