class Solution {
public:
    int maximumSwap(int num) {
        string numstr=to_string(num);
        int n=numstr.size();
        // int maxnum=num;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         swap(s[i],s[j]);
        //         maxnum=max(maxnum,stoi(s));
        //         swap(s[i],s[j]);
        //     }
        // }
        // return maxnum;
        int swapidx1=-1,swapidx2=-1,maxdigitIdx=-1;
        for(int i=n-1;i>=0;i--){
            if(maxdigitIdx==-1||numstr[i]>numstr[maxdigitIdx]){
                maxdigitIdx=i;
            }else if(numstr[i]<numstr[maxdigitIdx]){
                swapidx1=i;
                swapidx2=maxdigitIdx;
            }
        }
        if(swapidx1!=-1 && swapidx2!=-1){
            swap(numstr[swapidx1],numstr[swapidx2]);
        }
        return stoi(numstr);
    }
};