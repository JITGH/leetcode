class Solution {
public:
int findgcd(int a,int b){
    if(a==0) return b;
    return findgcd(b%a,a);
}
    string fractionAddition(string expression) {
        // int num=0;
        // int denom=1;
        // int i=0;
        // while(i<expression.size()){
        //     int curnum=0;
        //     int curdenom=0;

        //     bool isnegative=false;

        //     if(expression[i]=='-'||expression[i]=='+'){
        //         if(expression[i]=='-'){
        //         isnegative=true;
        //         }
        //         i++;
        //     }

        //     while(isdigit(expression[i])){
        //         int val=expression[i]-'0';
        //         curnum=curnum*10+val;
        //         i++;
        //     }

        //     if(isnegative) curnum*=-1;

        //     i++;

        //     while(i<expression.size() && isdigit(expression[i])){
        //         int val=expression[i]-'0';
        //         curdenom=curdenom*10+val;
        //         i++;
        //     }
        //     num=num*curdenom+denom*curnum;
        //     denom=denom*curdenom;
            
        // }
        // int gcd=abs(findgcd(num,denom));

        // num/=gcd;
        // denom/=gcd;

        // return to_string(num)+"/"+to_string(denom);

        int num = 0;
        int denom = 1;

        // separate expression into signed numbers
        vector<string> nums;
        int i = 0;
        if (expression[0] != '-') expression = '+' + expression;
        while (i < expression.size()) {
            int j = i + 1;
            while (j < expression.size() && expression[j] != '+' &&
                   expression[j] != '-') {
                j++;
            }
            nums.push_back(expression.substr(i, j - i));
            i = j;
        }

        for (int i = 0; i < nums.size(); ++i) {
            size_t pos = nums[i].find('/');
            int currNum = stoi(nums[i].substr(1, pos - 1));
            if (nums[i][0] == '-') currNum = -currNum;
            int currDenom = stoi(nums[i].substr(pos + 1));

            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;

            int gcd = abs(findgcd(num, denom));

            num /= gcd;
            denom /= gcd;
        }

        return to_string(num) + "/" + to_string(denom);

    }
};