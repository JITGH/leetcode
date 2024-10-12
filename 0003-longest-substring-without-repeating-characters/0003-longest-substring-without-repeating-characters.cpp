// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//     //   int count[256]={0};
//     //     int l=0;
//     //     int r=0;
//     //     int ans=0;
//     //     while(r<s.length()){
//     //         count[s[r]]++;
//     //         while(count[s[r]]>1){
//     //             count[s[l]]--;
//     //             l++;
//     //         }
//     //         ans=max(ans,(r-l+1));
//     //         r++;
//     //     }
//     //     return ans;


// //     int count[256]={-1};
// //     int maxlen=0;
// //     int l=0;
// //    // int r=0;
    
// //    // while(r<s.length()){
// //     for(int r=0;r<s.length();r++){
// //         // count[s[r]]++;
// //       //  if(count[s[r]]!=-1){
// //             if(count[s[r]]>=l){
// //                 l=count[s[r]]+1;
// //             }
// //        // }
// //         count[s[r]]=r;
// //     maxlen=max(maxlen,(r-l+1));
    
// //    // r++;
// //     }
// //     return maxlen;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> charIndex(128, -1);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};