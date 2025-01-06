class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
      vector<int>one;
      vector<int>ans;
      for(int i=0;i<n;i++){
        if(boxes[i]=='1'){
            one.push_back(i);
        }
      } 

      for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<one.size();j++){
            sum+=abs(i-one[j]);
            
        }
        ans.push_back(sum);
      }

      return ans;
    }
};