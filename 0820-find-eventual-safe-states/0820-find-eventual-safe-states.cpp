class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        set<int>blocked;
        vector<int>ans;
for(int k=0;k<n;k++)
{        
    bool con=true;
    for(int i=0;i<n;i++){
            bool lol=true;
            for(auto &it:graph[i]){
                if(blocked.find(it) == blocked.end()){
                    lol=false;
                    break;
                }
            }
            if(lol and blocked.find(i)==blocked.end()){
                ans.push_back(i);
                blocked.insert(i);
                    con =false;
                }
        }
        if(con)break;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};