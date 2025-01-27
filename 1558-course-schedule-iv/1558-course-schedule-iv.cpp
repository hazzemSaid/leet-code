class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        int n=pre.size();
        vector<int>indeg(num,0);
        vector<set<int>>v(num);
        unordered_map<int,vector<int>>graph;
        for(auto &it:pre){
            int x=it[0];
            int y=it[1];
            graph[x].push_back(y);
            indeg[y]++;
        }
        queue<int>topo;
        for(int i=0;i<num;i++){
            if(indeg[i] == 0){
                    topo.push({i});
            }
        }
        while(!topo.empty()){
            auto it=topo.front();
            topo.pop();
            for(auto nie:graph[it]){
                v[nie].insert(v[it].begin(),v[it].end());
                v[nie].insert(it);
                if(--indeg[nie] == 0){
                    topo.push(nie);
                }
            }
        }
        // for(int i=0;i<num;i++){
        //     cout<<i<<" ->>>"<<endl;;
        //     for(auto it:v[i])cout<<it<<" ";
        //     cout<<endl;
        // }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int y=queries[i][0];
            int x=queries[i][1];
            if(v[x].find(y) == v[x].end())ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};