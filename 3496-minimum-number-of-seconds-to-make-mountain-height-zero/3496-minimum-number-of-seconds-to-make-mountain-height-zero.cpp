class Solution {
public:
    bool iscan(long long t,int h,vector<int>& wt){
        long long th=0;
        for(int i:wt){
            long long left=0;
            long long right=1e6;
            while(left<=right){
                long long mid=left+(right-left)/2;
                if(i*mid*(mid+1)/2<=t) left=mid+1;
                else right=mid-1;
            }
            th+=right;
            if(th>=h) return true;
        }
        return false;
    }

    long long minNumberOfSeconds(int h, vector<int>& wt) {
        long long s=0;
        long long e=1e18;
        long long ans=0;
        while(s<=e){
              long long mid=s+(e-s)/2;
              if(iscan(mid,h,wt)){
                e=mid-1;
                ans=mid;
              }else{
                s=mid+1;
              }
        }
      return ans;
    }
};