class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int presum=0;
        int sortedsum=0;
        int chunks=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            presum+=arr[i];
            sortedsum+=i;
            if(presum==sortedsum) chunks++;
        }

        return chunks;
    }
};