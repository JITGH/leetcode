class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        int n = s.length();
    string str = s; 

     for (int i = 0; i < n; ++i) {
       
        int p = ((i + k) % n);
        str[i] = s[p];
    }

    return str;
    }
};