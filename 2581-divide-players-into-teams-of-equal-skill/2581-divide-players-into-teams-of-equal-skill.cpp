class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int sum=skill[0]+skill[n-1];
        long long prodsum=0;
       // prodsum+=(skill[0]*skill[n-1]);
       for(int i=0;i<n/2;i++){
        int current=skill[i]+skill[n-i-1];

        if(current!=sum){
            return -1;
        }
    prodsum+=((long long)skill[i]*(long long)skill[n-i-1]);
       }
        return prodsum;
    }
};