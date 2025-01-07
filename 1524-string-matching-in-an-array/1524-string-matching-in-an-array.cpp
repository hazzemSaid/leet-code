class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
         sort(words.rbegin(),words.rend(),[](auto a,auto b){
            return a.size()<b.size();
        });
        unordered_set<string>f;
        int sz=words.size();
        for(int i=0;i<sz;i++){
            cout<<words[i]<<endl;
            if(f.find(words[i]) != f.end()){
                ans.push_back(words[i]);
            }
            for(int j=0;j<words[i].size();j++){
                for(int k=1;k<words[i].size();k++){
                      string substring= words[i].substr(j,k);
                cout<<substring<<endl;
                f.insert(substring);
                }
            }
        }    
        return ans;
    }
};