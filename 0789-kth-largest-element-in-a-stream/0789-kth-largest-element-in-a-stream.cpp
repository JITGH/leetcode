// class KthLargest {  
// public:
//     vector<int>stream;
//     int k;
//     KthLargest(int k, vector<int>& nums) {
//         this->k=k;
//         for(int i:nums){
//             stream.push_back(i);
//         }
//         sort(stream.begin(),stream.end());
//     }
    
//     int add(int val) {
//         int index=getindex(val);
//         stream.insert(stream.begin()+index,val);

//         return stream[stream.size()-k];
//     }

//     private:
//     int getindex(int val){
//         int left=0;
//         int right=stream.size()-1;
//         while(left<=right){
//             int mid=(left+right)/2;
//             int midval=stream[mid];
//             if(midval==val) return mid;
//             else if(midval>val){
//                 right=mid-1;
//             }else{
//                 left=mid+1;
//             }
//         }
//         return left;
//     }
// };

// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * KthLargest* obj = new KthLargest(k, nums);
//  * int param_1 = obj->add(val);
//  */

//HEAP

class KthLargest {
private:
priority_queue<int,vector<int>,greater<int>>q;
int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums)
        add(num);
    }
      int add(int val) {
        if(q.size()<k || q.top()<val){
            q.push(val);
            if(q.size()>k){
                q.pop();
            }
        }
        return q.top();
      }
};