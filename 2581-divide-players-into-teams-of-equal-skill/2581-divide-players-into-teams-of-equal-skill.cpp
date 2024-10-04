class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
    //     int n=skill.size();
    //     sort(skill.begin(),skill.end());
    //     int sum=skill[0]+skill[n-1];
    //     long long prodsum=0;
    //    // prodsum+=(skill[0]*skill[n-1]);
    //    for(int i=0;i<n/2;i++){
    //     int current=skill[i]+skill[n-i-1];

    //     if(current!=sum){
    //         return -1;
    //     }
    // prodsum+=((long long)skill[i]*(long long)skill[n-i-1]);
    //    }
    //     return prodsum;


    int n=skill.size();
    int total=0;
    vector<int>skillfrequency(1001,0);

    for(int player:skill){
        total+=player;
        skillfrequency[player]++;
    }
    if(total%(n/2)!=0) return -1;
    int target=total/(n/2);

    long long ans=0;
    for(int player:skill){
        int partner=target-player;
        if(skillfrequency[partner]==0) return -1;

        ans+=(long long)player* (long long)partner;
        skillfrequency[partner]--;
    }
    return ans/2;
    }
};