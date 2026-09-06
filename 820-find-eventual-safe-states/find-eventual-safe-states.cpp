class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& adjL, vector<int>& vis, vector<int>& pathVis, vector<int>& check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto it : adjL[node]){
            if(!vis[it]){
                if(dfsCheck(it, adjL, vis, pathVis, check)){
                    check[node] = 0;
                    return true;
                }
            }
            else if(vis[it]==1 && pathVis[it]==1){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjL(V);

        for(int i=0 ; i<V ; i++){
            for(auto it : graph[i]){
                adjL[i].push_back(it);
            }
        }
        vector<int> ans;
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);

        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                dfsCheck(i, adjL, vis, pathVis, check);
            }
        }
        for(int i=0 ; i<V ; i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};