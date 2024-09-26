class Solution {
    private:
    int partition(vector<int>& nums,int l,int r){
        int pivot=nums[l];
        int left=l+1;
        int right=r;
        while(left<=right){
            if(nums[left]<pivot && nums[right]>pivot){
                swap(nums[left++],nums[right--]);
            }
            if(nums[left]>=pivot){
                left++;
            }
            if(nums[right]<=pivot){
                right--;
            }
        }
        swap(nums[l],nums[right]);
        return right;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int>pq;
        // for(int i=0;i<nums.size();i++){
        //     pq.push(nums[i]);

        // }
        // int f=k-1;
        // while(f>0){
        //     pq.pop();
        //     f--;
        // }
        // return pq.top();

        //STL -> SORT
        // nth_elemen ->builtin function
        //also can use instead of nth_element -> partial_sort
        // nth_element(nums.begin(),nums.begin()+k-1,nums.end(),greater<int>());
        // return nums[k-1];

    //min heap
//     priority_queue<int,vector<int>,greater<int>>pq;
//     for(int num:nums){
//         pq.push(num);
//         if(pq.size()>k){
//             pq.pop();
//         }
//     }
// return pq.top();

//maxheap

    // priority_queue<int>pq(nums.begin(),nums.end());
    // for(int i=0;i<k-1;i++){
    //     pq.pop();
    // }
    // return pq.top();

    //multiset -> min heap
    // multiset<int>mst;
    // for(int num:nums){
    // mst.insert(num);
    // if(mst.size()>k){
    //     mst.erase(mst.begin());
    // }
    // }
    // return *mst.begin();/
  //multiset -> max heap

    // multiset<int,greater<int>>mst(nums.begin(),nums.end());
    // for(int i=0;i<k-1;i++){
    //     mst.erase(mst.begin());
    // }
    // return *mst.begin();

    //partition ->quicksort ->o(n)
    int left=0;
    int right=nums.size()-1;
    int kth=0;
    while(true){
        int idx=partition(nums,left,right);
        if(idx==k-1){
            kth=nums[idx];
            break;
        }
        if(idx<k-1){
            left=idx+1;
        }
        else{
            right=idx-1;
        }
    }
return kth;
  }
};