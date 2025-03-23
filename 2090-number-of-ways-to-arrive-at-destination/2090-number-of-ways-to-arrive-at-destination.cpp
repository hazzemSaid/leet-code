class Solution {
public:
    int countPaths(int n, vector<vector<int>>& r) {
            const int mod = 1e9 + 7;
        vector<long long> dist(n, 1e18);
        vector<long long>path_cnt(n,0);
        vector<vector<pair<int,int>>> graph(n);

        for(auto it : r) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        dist[0] = 0;
        path_cnt[0]=1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            for(auto &i : graph[it.second]) {
                if((i.second + it.first) < dist[i.first]) {
                    pq.push({i.second + it.first, i.first});
                    dist[i.first] = (i.second + it.first) % mod;
                    path_cnt[i.first] = path_cnt[it.second];
                } else if(dist[i.first] == (i.second + it.first) % mod) {
                    path_cnt[i.first]= (path_cnt[i.first]+ path_cnt[it.second]) % mod;
                }
                
            }
        }

        return path_cnt[n - 1] % mod;
    }
};