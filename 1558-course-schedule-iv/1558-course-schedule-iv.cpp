class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        // Adjacency list for graph
        vector<vector<int>> graph(num);
        vector<int> indeg(num, 0);
        vector<set<int>> prerequisites(num); // Store prerequisites for each course
        
        // Build the graph and calculate in-degrees
        for (auto& edge : pre) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            indeg[v]++;
        }
        
        // Topological sort using BFS
        queue<int> topo;
        for (int i = 0; i < num; i++) {
            if (indeg[i] == 0) {
                topo.push(i);
            }
        }
        
        while (!topo.empty()) {
            int node = topo.front();
            topo.pop();
            
            // Add current node's prerequisites to its neighbors
            for (int neighbor : graph[node]) {
                prerequisites[neighbor].insert(prerequisites[node].begin(), prerequisites[node].end());
                prerequisites[neighbor].insert(node);
                
                // Decrease in-degree and push to queue if zero
                if (--indeg[neighbor] == 0) {
                    topo.push(neighbor);
                }
            }
        }
        
        // Answer queries
        vector<bool> ans;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            ans.push_back(prerequisites[v].count(u) > 0);
        }
        return ans;
    }
};
