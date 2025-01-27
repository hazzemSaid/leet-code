class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n=fav.size();
        vector<int> indeg(n, 0);
        vector<int> depth(n, 1);
        for(int i=0;i<n;i++){
            indeg[fav[i]]++;           
        }
        queue<int>topo;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0)topo.push(i);
        }
        while(!topo.empty()){
            int node=topo.front();
            topo.pop();
            depth[fav[node]]=max(depth[fav[node]],depth[node]+1);
            if(--indeg[fav[node]] ==0)topo.push(fav[node]);
        }
        int longlength=0;
        int twolength=0;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0)continue;
            int node=i;
            int depcycle=0;
            while(indeg[node]){
                indeg[node]=0;
                depcycle++;
                node=fav[node];
            }
            if(depcycle == 2){
                twolength+=depth[node]+depth[fav[node]];
            }
            else if (depcycle>2){
                longlength=max(longlength,depcycle);
            }
        }
        return max(longlength,twolength);
    }
};