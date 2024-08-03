class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mpp;
        int n=target.size();
        int m=arr.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            mpp[target[i]]++;
            mpp[arr[i]]--;
        }

        for(auto it:mpp){
            if(it.second!=0) return false;
        }
        return true;
    }
};