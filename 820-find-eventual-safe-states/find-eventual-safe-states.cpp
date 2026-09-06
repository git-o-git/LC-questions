class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& adjL, vector<bool>& vis, vector<bool>& pathVis, vector<bool>& check){
        vis[node] = true;
        pathVis[node] = true;
        check[node] = false;

        for(auto it : adjL[node]){
            if(!vis[it]){
                if(dfsCheck(it, adjL, vis, pathVis, check)){
                    check[node] = false;
                    return true;
                }
            }
            else if(vis[it] && pathVis[it]){
                check[node] = false;
                return true;
            }
        }
        pathVis[node] = false;
        check[node] = true;
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
        vector<bool> vis(V, false), pathVis(V, false), check(V, false);

        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                dfsCheck(i, adjL, vis, pathVis, check);
            }
        }

        for(int i=0 ; i<V ; i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};