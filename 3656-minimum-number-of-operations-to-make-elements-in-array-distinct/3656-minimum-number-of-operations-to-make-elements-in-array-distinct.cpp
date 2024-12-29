class Solution {
public:
// void rem(vector<int>& arr) {
    //     int elementsToRemove =min(3, static_cast<int>(arr.size()));
    //     arr.erase(arr.begin(), arr.begin() + elementsToRemove);
    // }
    //int minimumOperations(vector<int>& nums) {
    //      if (nums.empty()) return 0;
        
    //     int op= 0;
    //   vector<int> cur = nums;
        
    //     while (dup(cur) && !cur.empty()) {
    //         rem(cur);
    //         op++;
    //     }
        
    //     return op;

    int minimumOperations(vector<int>& nums) {
    vector<int> freq(101, 0);
    for(int i = nums.size()-1; i >= 0; --i){
        if(++freq[nums[i]] > 1) return ceil((double)(i + 1)/3);
    }
    return 0;
}
   // }
// private:
//     bool dup(vector<int>& arr) {
//       unordered_set<int> unique(arr.begin(), arr.end());
//         return unique.size() != arr.size();
//     }
    
    
};