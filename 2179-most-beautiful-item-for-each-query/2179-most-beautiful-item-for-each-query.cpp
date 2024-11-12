class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        int m=items.size();
        vector<int>ans(n);
        sort(items.begin(),items.end(),[](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        int maxbeauty=items[0][1];
        for(int i=0;i<m;i++){
            maxbeauty=max(maxbeauty,items[i][1]);
            items[i][1]=maxbeauty;
        }

        for(int i=0;i<n;i++){
            ans[i]=binarySearch(items,queries[i]);
        }
        return ans;
    }


    int binarySearch(vector<vector<int>>& items,int price){
        int n=items.size();
        int l=0;
        int r=n-1;
        int maxbeauty=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(price<items[mid][0]){
                r=mid-1;
            }else{
                maxbeauty=max(maxbeauty,items[mid][1]);
                l=mid+1;
            }
        }
        return maxbeauty;
    }
};