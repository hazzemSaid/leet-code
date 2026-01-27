class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> mp(50001);
       priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;
        for (auto& it : edges) {
            mp[it[0]].push_back({it[1], it[2]});
            mp[it[1]].push_back({it[0], it[2] * 2});
        }
vector<long long> dis(n, LLONG_MAX);   
        pq.push({0,0});
        dis[0]=0;
        while (!pq.empty()) {
         auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dis[u]) continue;
            
            // Goal reached
            if (u == n - 1) return (int)cost;

            for (auto& edge : mp[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dis[u] + weight < dis[v]) {
                    dis[v] = dis[u] + weight;
                    pq.push({dis[v], v});
                }
            }
        }
        return -1;
    }
};