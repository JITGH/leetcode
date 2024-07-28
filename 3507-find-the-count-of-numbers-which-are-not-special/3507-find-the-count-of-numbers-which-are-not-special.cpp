class Solution {
    private:
    vector<int> prime(int l) {
    vector<bool> ip(l + 1, true);
    ip[0] = ip[1] = false; 
    for (int i = 2; i * i <= l; ++i) {
        if (ip[i]) {
            for (int j = i * i; j <= l; j += i) {
                ip[j] = false;
            }
        }
    }
    vector<int> p;
    for (int i = 2; i <= l; ++i) {
        if (ip[i]) {
            p.push_back(i);
        }
    }
    return p;
    }
public:
    int nonSpecialCount(int l, int r) {
            int li = sqrt(r);
    vector<int> p = prime(li);

    int c= 0;
    for (int i : p) {
        int sq =i * i;
        if (sq > r) break;
        if (sq >= l) {
            ++c;
        }
    }

    int to = r - l + 1;
    int ns = to - c;

    return ns;

    }
};