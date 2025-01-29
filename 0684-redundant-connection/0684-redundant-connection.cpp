class Solution {
public:
// using find union find algorithm 
//by size 
int par[1001]{0};
int size[1001]{0};
void init(){
    for(int i=0;i<1001;i++)par[i]=i,size[i]=1;
}
int findpar(int x){
    //find par of x 
    if(par[x] == x)return x;
    return par[x]=findpar(par[x]);
}
void unionfind(int X,int Y){
    //union two parent by size
    int x=findpar(X);
    int y=findpar(Y);
    if(x == y)return;
    if(size[x] <size[y]){
        size[y]+=size[x];
        par[x]=y;
    }
    else{
        size[x]+=size[y];
        par[y]=x;
    }
    
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            init();
            vector<int>ans;
            for(auto &it:edges){
                if(findpar(it[0]) == findpar(it[1])){
                    ans=(it);
                }
                else{
                   unionfind(it[0],it[1]);
                }
            }

return ans;
    }
};