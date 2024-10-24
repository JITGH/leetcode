class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> v;
        string str = "";
        for (char c : target) {
            str += 'a';
            v.push_back(str);

            while (str.back() != c) {
                str.back() = (str.back() == 'z') ? 'a' : str.back() + 1;
                v.push_back(str);
            }
        }
        return v;
    }
};