class Solution {
public:
long long MOD = 1000000007;
    int minNonZeroProduct(int p) {
        long long val = pow(2,p);    
        val--;                          // val = 2^p -1 
        long long K = val/2;            // we can make val/2 numbers to equal to "1" and "val-1" by swapping bits 
        long long N = val-1;            
        long long ans = expn(N,K);      // Multiplying "val-1" K times
        return ans*((val)%MOD)%MOD;     // After performing swapping of bits, minimum product we can get is (val-1)^K * (val)
    }
    long long expn(long long N, long long K){
        if(K==0) return 1;
        if(K==1) return N%MOD;
        if(K%2 ==0){
            long long temp = expn(N,K/2);
            return (temp*temp)%MOD;
        }else{
            long long temp = expn(N,K/2);
            temp = (temp*temp)%MOD;
            return (temp*(N%MOD))%MOD;
    }
    }
};