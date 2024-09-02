class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // int sum=0;
        // for(int i=0;i<chalk.size();i++){
        //     sum+=chalk[i];
        //     if(sum>k){
        //         break;
        //     }
        // }

        // k=k%sum;
        // for(int i=0;i<chalk.size();i++){
        //     if(k<chalk[i]){
        //         return i;
        //     }
        //     k-=chalk[i];
        // }
        // return 0;

        int n=chalk.size();
        vector<long>prefixsum(n);
        prefixsum[0]=chalk[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+chalk[i];

        }
        long sum=prefixsum[n-1];
        long remaining=k%sum;
        return binarysearch(prefixsum,remaining);
    }

    int binarysearch(vector<long>&arr,long tar){
        int low=0;
        int high=arr.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
           if(arr[mid]<=tar){
            low=mid+1;

           }else{
            high=mid;
           }
        }
        return high;
    }
};