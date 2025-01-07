class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        //sort the words from big lenght ot small 
         sort(words.rbegin(),words.rend(),[](auto a,auto b){
            return a.size()<b.size();
        });
        int sz=words.size();
        //make the boolen for dubilcate substring
        bool vis[3002];
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(vis[j] == true)continue;
                //if i find the words[j] into words[i]
                auto find=words[i].find(words[j]);
                if(find != string::npos){
                    vis[j]=true;
                    ans.push_back(words[j]);
                }
            }
        }
        return ans;
    }
};