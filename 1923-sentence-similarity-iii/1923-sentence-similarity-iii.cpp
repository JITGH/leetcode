class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        istringstream iss1(s1);
        deque<string>d1((istream_iterator<string>(iss1)),
        istream_iterator<string>());
        istringstream iss2(s2);

        deque<string>d2((istream_iterator<string>(iss2)),
        istream_iterator<string>());

        while(!d1.empty() && !d2.empty() && d1.front()==d2.front()){
            d1.pop_front();
            d2.pop_front();
        }
        while(!d1.empty() && !d2.empty() && d1.back()==d2.back()){
            d1.pop_back();
            d2.pop_back();
        }
        return d1.empty()||d2.empty();
    }
};