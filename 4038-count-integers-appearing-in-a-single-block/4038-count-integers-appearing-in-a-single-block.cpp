class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> appeared;
        unordered_set<int> invalid;

        int i = 0;
        while (i < n) {
            int val = nums[i];
            int j = i;
            while (j < n && nums[j] == val) j++;  // find end of this contiguous run

            if (appeared.count(val)) {
                invalid.insert(val);   // val showed up in an earlier, separate run
            }
            appeared.insert(val);

            i = j;  // jump to next run
        }

        return (int)appeared.size() - (int)invalid.size();
    }
};