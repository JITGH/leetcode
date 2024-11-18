// class Solution {
// public:
//     vector<int> decrypt(vector<int>& code, int k) {
//         vector<int>ans(code.size(),0);
//         if(k==0) return ans;
//         // for(int i=0;i<ans.size();i++){
// //             if(k>0){
// //                 for(int j=i+1;j<i+k+1;j++){
// //                     ans[i]+=code[j%code.size()];
// //                 }
// //             }
// //             else{
// //                 for(int j=i-abs(k);j<i;j++){
// //                     ans[i]+=code[(j+code.size())%code.size()];
// //                 }
// //             }
// //         }
// // return ans;

//             int st=1,end=k,sum=0;
//             if(k<0){
//                 st=code.size()-abs(k);
//                 end=code.size()-1;
//             }
//             for(int i=st;i<=end;i++) sum+=code[i];

//             for(int i=0;i<code.size();i++){
//                 ans[i]-=code[st%code.size()];
//                 sum+=code[(end+1)%code.size()];
//                 st++;
//                 end++;
//             }

//     return ans;
//     }
// };

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if (k == 0) return result;
        // Define the initial window and initial sum
        int start = 1, end = k, sum = 0;
        // If k < 0, the starting point will be end of the array.
        if (k < 0) {
            start = code.size() - abs(k);
            end = code.size() - 1;
        }
        for (int i = start; i <= end; i++) sum += code[i];
        // Scan through the code array as i moving to the right, update the
        // window sum.
        for (int i = 0; i < code.size(); i++) {
            result[i] = sum;
            sum -= code[start % code.size()];
            sum += code[(end + 1) % code.size()];
            start++;
            end++;
        }
        return result;
    }
};