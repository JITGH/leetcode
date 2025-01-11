
    //     if(s.size()<k) return false;
    //     if(s.size()==k) return true;
    //    // unordered_map<char,int>mpp;
    //    vector<int>hash(26,0);
    //     for(int i=0;i<s.size();i++){
    //        // mpp[s[i]]++;
    //        hash[s[i]-'a']++;
    //     }
    //     int cnt=0;
    //     for(int i=0;i<26;i++){
    //         if(hash[i]%2==1){
    //             cnt++;
    //         }
    //     }
    //     return cnt<=k;

    class Solution {
public:
    bool canConstruct(string s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize oddCount as an integer bitmask
        int oddCount = 0;

        // Update the bitmask for each character in the string
        for (char chr : s) {
            oddCount ^= 1 << (chr - 'a');
        }

        // Count the number of set bits in the bitmask
        int setBits = __builtin_popcount(oddCount);

        // Return if the number of odd frequencies is less than or equal to k
        return  setBits<= k;
    }
};
