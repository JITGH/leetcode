class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XORele=0;
        for(int el:derived)
        XORele^=el;

        return (XORele==0);
    }
};