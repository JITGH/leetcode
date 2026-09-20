class Solution {
public:
    int reverseDegree(string s) {
        //long long ans=1;
        long long prodsum=0;
        for(int i=0;i<s.size();i++){
            int num=26-(s[i]-'a');
            prodsum+=num*(i+1);
            //cout<<num;
        }


        return prodsum;
    }
};