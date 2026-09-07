class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<int> endsWith(26, 0);
        int total = 0;

        for (char ch : s) {
            int idx = ch - 'a';
            int newSubseq = (total + 1 - endsWith[idx] + MOD) % MOD;
            total = (total + newSubseq) % MOD;
            endsWith[idx] = (endsWith[idx] + newSubseq) % MOD;
        }

        return total;
    }
};