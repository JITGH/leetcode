class RandomizedSet {
public:
vector<int>ans;
unordered_map<int,int>m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false;
        ans.push_back(val);
        m[val]=ans.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        // int last=ans.back();
        // m[last]=m[val];
        // ans[m[val]]=last;
        // ans.pop_back();
        // m.erase(val);
        // return true;

        int last=ans.back();
        ans[m[val]]=last;
        ans.pop_back();
        m[last]=m[val];
        m.erase(val);
        return true;

    }
    
    int getRandom() {
        return ans[rand()%ans.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */