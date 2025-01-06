class Solution {
public:
    vector<int> minOperations(string boxes) {
    //     int n=boxes.size();
    //   vector<int>one;
    //   vector<int>ans;
    //   for(int i=0;i<n;i++){
    //     if(boxes[i]=='1'){
    //         one.push_back(i);
    //     }
    //   } 

    //   for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=0;j<one.size();j++){
    //         sum+=abs(i-one[j]);
            
    //     }
    //     ans.push_back(sum);
    //   }

    //   return ans;

          int n=boxes.size();
        vector<int>ans(n,0);
        int ops=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            ans[i]+=ops;
            cnt+=(boxes[i]=='1')?1:0;
            ops+=cnt;
        }

        ops=0,cnt=0;
        for(int i=n-1;i>=0;--i){
            ans[i]+=ops;
            cnt+=(boxes[i]=='1')?1:0;
            ops+=cnt;
        }
    return ans;
    }
};