class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int minn = INT_MAX;
        map<int,int>mp1,mp2;
        for(auto &it:basket1){
            mp1[it]++;
            minn=min(minn,it);
        }
         for(auto &it:basket2){
            minn=min(minn,it);
            mp2[it]++;
        }
        vector<int>v1,v2;
        for(auto &it:mp1){
            if(mp2.find(it.first) != mp2.end()){
                int cnt = it.second + mp2[it.first];

                if(cnt%2==1)return -1;
                cnt/=2;
                if(it.second > cnt){
                    cnt=it.second-cnt;
                    while(cnt--)v1.push_back(it.first);
                }
            }
            else{
                 int cnt = it.second ;
                if(cnt%2==1)return -1;
                cnt/=2;
                if(it.second > cnt){
                    cnt=it.second-cnt;
                    while(cnt--)v1.push_back(it.first);
                }
            }
        }
        // for(auto &it:v1)cout<<it<<endl;
        //------------
         for(auto &it:mp2){
            if(mp1.find(it.first) != mp1.end()){
                int cnt = it.second + mp1[it.first];

                if(cnt%2==1)return -1;
                cnt/=2;
                if(it.second > cnt){
                    cnt=it.second-cnt;
                    while(cnt--)v2.push_back(it.first);
                }
            }
            else{
                 int cnt = it.second ;
                if(cnt%2==1)return -1;
                cnt/=2;
                if(it.second > cnt){
                    cnt=it.second-cnt;
                    while(cnt--)v2.push_back(it.first);
                }
            }
        }
        // cout<<endl;
        // for(auto &it:v2)cout<<it<<endl;
        // return v1.size()*minn*2;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        long long ans=0;
        int sz=v1.size();
        for(int i=0;i<sz;i++){
        ans+=min({v1[i],v2[sz-(i+1)],minn*2});
        }
        return ans;
    }
};