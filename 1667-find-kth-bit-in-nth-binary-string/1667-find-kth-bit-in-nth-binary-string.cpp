// // class Solution {
// // public:
// //     char findKthBit(int n, int k) {
// //         string sequence="0";

// //         for(int i=1;i<n && k>sequence.length();i++){
// //             sequence+='1';

// //             string temp=sequence;
// //             for(int j=temp.length()-2;j>=0;--j){
// //                 char invertbit=(temp[j]=='1')?'0':'1';
// //                 sequence+=invertbit;
// //             }

// //         }
// //         return sequence[k-1];
// //     }
// // };

// class Solution {
// public:
//     char findKthBit(int n, int k) {
//         string sequence="0";

//         for(int i=1;i<n && k>sequence.length();i++){
//             sequence+='1';

//             string temp=sequence;
//             for(int j=temp.length()-2;j>=0;--j){
//                 char invertbit=(temp[j]=='1')?'0':'1';
//                 sequence+=invertbit;
//             }

//         }
//         return sequence[k-1];
//     }
// };

class Solution{
public:
char findKthBit(int n, int k){
    int invertbitcount=0;
    int len=(1<<n)-1;

    while(k>1){
        if(k==len/2+1){
            return invertbitcount%2==0?'1':'0';

        }
        if(k>len/2){
            k=len+1-k;
            invertbitcount++;
        }
        len/=2;
    }
    return invertbitcount%2==0?'0':'1';
}
};