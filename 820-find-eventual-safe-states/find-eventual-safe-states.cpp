class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjR(V);
        vector<int> indegree(V, 0);

        for(int i=0 ; i<V ; i++){
            for(auto it : graph[i]){
                adjR[it].push_back(i);     // reverse of (i->it) means it->i
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0 ; i<V ; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adjR[node]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }
            ans.push_back(node);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};