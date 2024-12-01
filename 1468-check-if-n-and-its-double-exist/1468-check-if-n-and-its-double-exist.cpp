// Brute Force Two Pointer Soln
// Time O(n.n)
// Space O(1)

class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        int pointer_one = -1;
        int pointer_two = -1;
        
        for (pointer_one = 0; pointer_one < arr.size(); pointer_one++) {
            int n = arr[pointer_one];
            for (pointer_two = pointer_one + 1; pointer_two < arr.size(); pointer_two++) {
                int m = arr[pointer_two];
                if ( n == (2 * m) || m == (2 * n)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};