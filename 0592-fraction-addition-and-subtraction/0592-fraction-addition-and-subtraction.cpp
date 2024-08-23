class Solution {
public:
int findgcd(int a,int b){
    if(a==0) return b;
    return findgcd(b%a,a);
}
    string fractionAddition(string expression) {
        int num=0;
        int denom=1;
        int i=0;
        while(i<expression.size()){
            int curnum=0;
            int curdenom=0;

            bool isnegative=false;

            if(expression[i]=='-'||expression[i]=='+'){
                if(expression[i]=='-'){
                isnegative=true;
                }
                i++;
            }

            while(isdigit(expression[i])){
                int val=expression[i]-'0';
                curnum=curnum*10+val;
                i++;
            }

            if(isnegative) curnum*=-1;

            i++;

            while(i<expression.size() && isdigit(expression[i])){
                int val=expression[i]-'0';
                curdenom=curdenom*10+val;
                i++;
            }
            num=num*curdenom+denom*curnum;
            denom=denom*curdenom;
            
        }
        int gcd=abs(findgcd(num,denom));

        num/=gcd;
        denom/=gcd;

        return to_string(num)+"/"+to_string(denom);
    }
};