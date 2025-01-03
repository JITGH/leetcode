class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    //  sort(nums.begin(),nums.end());
    //  return nums;
    heapSort(nums);
    return nums;
    }

    	void siftDown(vector<int>& nums, int n, int i){
        int biggest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if(l < n && nums[biggest] < nums[l])
            biggest = l;
        if(r < n && nums[biggest] < nums[r])
            biggest = r;
        if(biggest != i){
            swap(nums[i], nums[biggest]);
            siftDown(nums, n, biggest);
        }
    }
    
	// heapSort(nums);
    void heapSort(vector<int>& nums){
        // heapify stage (bottom up approach)
        for(int i = nums.size() / 2 - 1; i >= 0; i--)
            siftDown(nums, nums.size(), i);
        // sorting stage
        for(int i = nums.size() - 1; i > 0; i--){
            swap(nums[0], nums[i]);
            siftDown(nums, i, 0);
        }
    }
    
};
