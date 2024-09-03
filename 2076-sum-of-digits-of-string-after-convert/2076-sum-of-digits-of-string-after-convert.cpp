class Solution {
public:

    int getLucky(string s, int k) {
        int n=s.size();
       int ans=0;
        for(char ch:s){
            int pos=ch-'a'+1;
            while(pos>0){
                ans+=pos%10;
                pos/=10;
            }
        }
        for(int i=1;i<k;i++){
            int tot=0;
            while(ans>0){
                tot+=ans%10;
                ans/=10;
            }
            ans=tot;
        }


        return ans;
    }
};