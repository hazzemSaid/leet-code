class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>m;
        for(int i=0;i<n;i++){
            m.push_back({nums[i],i});
        }
        sort(m.begin(),m.end());
        vector<vector<pair<int,int>>>gro={{{m[0].first,m[0].second}}};
        int prv=m[0].second;
        int na=0;
        for(int i=1;i<n;i++){
            int vl=m[i].first,indx=m[i].second;
            if(abs(vl-nums[prv]) <= limit){
                gro[na].push_back({vl,indx});
            }
            else{
                gro.push_back({{vl,indx}});
                na++;
            }
        prv=indx;
        }
        vector<int>res(n);
        for(auto it:gro){
            vector<int>value,indx;
            for(auto i:it){
                cout<<i.first<<" "<<i.second<<endl; 
                value.push_back(i.first);
                indx.push_back(i.second);
            }
            cout<<endl;
            sort(indx.begin(),indx.end());
            for(int i=0;i<indx.size();i++)res[indx[i]]=value[i];
            
        }
        return res;
    }
};