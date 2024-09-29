class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        if(n<m) return {};
        vector<int>fre(26,0);
        vector<int>cfrq(26,0);

        for(int i=0;i<m;i++){
            fre[p[i]-'a']++;
            cfrq[s[i]-'a']++;
        }
        vector<int>ans;
        if(fre==cfrq) ans.push_back(0);

        for(int i=m;i<n;i++){
            cfrq[s[i-m]-'a']--;
            cfrq[s[i]-'a']++;

            if(cfrq==fre) ans.push_back(i-m+1);
        }
        return ans;
    }
};