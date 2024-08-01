//Solution 01:
/**class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size(), p=1;
        vector<int> l(n), r(n);
        
        for(int i=0; i<n; i++){
            p *= nums[i];
            l[i]=p;
        }
        
        p=1;
        
        for(int i=n-1; i>=0; i--){
            p *= nums[i];
            r[i]=p;
        }
        
        nums[0]=r[1]; nums[n-1]=l[n-2];
        
        for(int i=1; i<n-1; i++){
            nums[i]= l[i-1]*r[i+1];
        }
        
        return nums;
    }
};**/

//Solution 02:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size(), p=1,po=1;
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            // p *= nums[i];
            // ans[i]=p;
            ans[i]=p;
            p*=nums[i];
        }
        
       // int product=1;
        for(int i=n-1; i>=0; i--){
            // ans[i]= ans[i-1]*product;
            // product *= nums[i];
            ans[i]*=po;
            po*=nums[i];
        }
       // ans[0]=product;
        
        return ans;
    }
};