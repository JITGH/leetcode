class Solution {
    private:
    bool candist(int x,vector<int>& quantities,int n){
        int j=0;
        int rem=quantities[j];

        for(int i=0;i<n;i++){
            if(rem<=x){
                j++;
                if(j==quantities.size()){
                    return true;
                }
                else{
                    rem=quantities[j];
                }
            }else{
                rem-=x;
            }
        }
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left=0;
        int right=*max_element(quantities.begin(),quantities.end());
        while(left<right){
            int mid=left+(right-left)/2;
           // cout<<mid<<"\n";
            if(candist(mid,quantities,n)){
                right=mid;
               // cout<<"ri ->"<<right<<" \n";
            }else{
                left=mid+1;
            //    cout<<"lef->"<<left<<"\n";
            }
        }
        return left;
    }
};