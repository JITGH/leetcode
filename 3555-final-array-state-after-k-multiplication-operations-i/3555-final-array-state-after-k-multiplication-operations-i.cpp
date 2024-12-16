class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        // for(int i=0;i<k;i++){
        //     int mini=0;
        //     for(int j=0;j<n;j++){
        //         if(nums[j]<nums[mini]){
        //             mini=j;
        //         }
        //     }
        //     nums[mini]*=multiplier;
    
        // }
        // return nums;



        vector<pair<int,int>>heap;
        for(int i=0;i<n;i++){
            heap.push_back({nums[i],i});
        }

        make_heap(heap.begin(),heap.end(),greater<>());

        while(k--){
            pop_heap(heap.begin(),heap.end(),greater<>());
            auto[value,i]=heap.back();
            heap.pop_back();

            nums[i]*=multiplier;
            heap.push_back({nums[i],i});
            push_heap(heap.begin(),heap.end(),greater<>());
        }
        return nums;
    }

};