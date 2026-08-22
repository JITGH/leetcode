class Solution {
public:
int digit_sum(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }

    return sum;
}

int digit_product(int num){
    int prod=1;
    while(num>0){
        prod=prod*(num%10);
        num/=10;
    }

    return prod;
}


    bool checkDivisibility(int n) {
       int num=n;
       int total_sum= digit_sum(num)+digit_product(num);

       return n%total_sum==0;
    }
};