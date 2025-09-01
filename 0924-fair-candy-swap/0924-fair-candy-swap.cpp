class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
       int sa=0,sb=0;
       for(int i=0;i<aliceSizes.size();i++){
           sa+=aliceSizes[i];
       } 
       for(int i=0;i<bobSizes.size();i++){
           sb+=bobSizes[i];
       } 
       int diff=(sa-sb)/2;
       set<int>bob;
     //  for(int i=0;i<)
     for(int i = 0; i < bobSizes.size(); i++){
			bob.insert(bobSizes[i] + diff);
		}
		for(int i = 0; i < aliceSizes.size(); i++){
			if(bob.find(aliceSizes[i]) != bob.end()){    
				return {aliceSizes[i], aliceSizes[i] - diff};
			}
		}
        return {};
    }
};