class Solution {
    private:
    vector<vector<int>>makegraph(vector<vector<int>>& edges){
        int n=edges.size();
        vector<vector<int>>gr(n+1);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        return gr;
    }

    void findFar(int node,int par,int dis,vector<vector<int>>& gr,pair<int,int>& res){
        if(dis>res.first){
            res={dis,node};
        }
        for(auto ne:gr[node]){
            if(ne!=par){
                findFar(ne,node,dis+1,gr,res);
            }
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto gr1=makegraph(edges1),gr2=makegraph(edges2);
        pair<int,int>res1={INT_MIN,-1},res2={INT_MIN,-1};
        findFar(0,-1,0,gr1,res1);
        findFar(res1.second,-1,0,gr1,res2);
        int dia1=res2.first;


        res1={INT_MIN,-1},res2={INT_MIN,-1};
        findFar(0,-1,0,gr2,res1);
        findFar(res1.second,-1,0,gr2,res2);
        int dia2=res2.first;
        int combdia=ceil(dia1/2.0) + ceil(dia2/2.0) + 1;
        return max({dia1,dia2,combdia});
    }
};