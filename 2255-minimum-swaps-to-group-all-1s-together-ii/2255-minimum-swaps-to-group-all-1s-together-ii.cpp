class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int zero=swaphelp(nums,0);
        int one=swaphelp(nums,1);
        return min(zero,one);
    }

    int swaphelp(vector<int>& nums,int v){
        int n=nums.size();
        int tc=0;
        for(int i=0;i<n;i++){
            if(nums[i]==v) tc++;
        }

        int s=0;
        int e=0;
        int maxw=0,curw=0;
        while(e<tc){
            if(nums[e++]==v) curw++;
        }
        maxw=max(maxw,curw);
        while(e<n){
            if(nums[s++]==v) curw--;
            if(nums[e++]==v) curw++;
            maxw=max(maxw,curw);
        }
        return tc-maxw;
    }
};