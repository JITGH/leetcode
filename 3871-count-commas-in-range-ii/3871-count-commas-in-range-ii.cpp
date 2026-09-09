class Solution {
public:
    long long countCommas(long long n) {
        long long total_comma=0;
        long long threshold=1000;

        while(n>=threshold){
            total_comma+=(n-threshold+1);

            if(threshold>LLONG_MAX/1000) break;
            threshold*=1000;
        }
        return total_comma;
    }
};