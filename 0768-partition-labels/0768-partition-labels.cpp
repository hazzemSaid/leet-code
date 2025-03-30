class Solution {
public:
    vector<int> partitionLabels(string s) {
        int max_w=0;
        int l=0,r=0;
        int sz=s.size();
        map<char,pair<int,int>>mp;
        for(int i=0;i<sz;i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]]={i,i};
            }
            else{
                mp[s[i]].second=i;
            }
        }
        vector<int>ans;
        while(r<sz){
            max_w=max(mp[s[r]].second,max_w);
            if(max_w == r){
                ans.push_back(r-l+1);
                r++;
                l=r;
                max_w=0;
            }
            else
            r++;
        }
        return ans;
    }
};