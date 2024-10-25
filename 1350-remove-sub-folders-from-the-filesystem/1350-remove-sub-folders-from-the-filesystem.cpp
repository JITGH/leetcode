class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // unordered_set<string>st(folder.begin(),folder.end());
        // vector<string>ans;
        // for(string& f:folder){
        //     bool isSubFolder=false;
        //     string prefix=f;

        //     while(!prefix.empty()){
        //         size_t pos=prefix.find_last_of('/');
        //         if(pos==string::npos) break;

        //         prefix=prefix.substr(0,pos);

        //         if(st.count(prefix)){
        //             isSubFolder=true;
        //             break;
        //         }
        //     }
        //     if(!isSubFolder){
        //         ans.push_back(f);
        //     }
        // }
        // return ans;

        sort(folder.begin(),folder.end());

        vector<string>result;
        result.push_back(folder[0]);

        for(int i=1;i<folder.size();i++){
            string lastfolder=result.back();
            lastfolder+='/';

            if(folder[i].compare(0,lastfolder.size(),lastfolder)!=0){
                result.push_back(folder[i]);
            }
        }
        return result;
    }
};