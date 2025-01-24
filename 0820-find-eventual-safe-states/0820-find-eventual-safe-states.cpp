class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
        map<int,vector<int>>mp;
        priority_queue<int>t;
        int n=graph.size();
        vector<int>ans;
        vector<int>out(n);
        for(int i=0;i<n;i++){
            for(auto &it:graph[i]){
                mp[it].push_back(i);
                out[i]++;
            }
            if(out[i] == 0)t.push(i);
        }
        while(!t.empty()){
            auto it=t.top();
            t.pop();
            ans.push_back(it);
            for(auto &i:mp[it]){
                if(--out[i] == 0)t.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};