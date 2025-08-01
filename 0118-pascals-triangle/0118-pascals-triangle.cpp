class Solution {
public:
void fun(vector<vector<int>>&res,int indx,int numRows,int sz){
    if(numRows == 0)return;
    res[indx].resize(sz);
    res[indx][0]=1;
    res[indx][sz-1]=1;
    for(int i=1;i<sz-1;i++){
        res[indx][i]=res[indx-1][i-1]+res[indx-1][i];
    }
    fun(res,indx+1,numRows-1,sz+1);
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res(numRows);
        res[0]={1};
        fun(res,1,numRows-1,2);
        return res;
    }
};