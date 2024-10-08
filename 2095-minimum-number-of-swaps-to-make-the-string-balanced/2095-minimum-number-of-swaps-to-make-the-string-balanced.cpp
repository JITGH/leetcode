class Solution {
public:
    int minSwaps(string s) {
        int stacksize=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='[') stacksize++;
            else{
                if(stacksize>0) stacksize--;
            }
        }
        return (stacksize+1)/2;

    }
};