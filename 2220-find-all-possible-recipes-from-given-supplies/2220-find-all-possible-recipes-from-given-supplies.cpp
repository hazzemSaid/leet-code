class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_map<string,int>top_mp;
        unordered_map<string,vector<string>>nie_mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                nie_mp[ingredients[i][j]].push_back(recipes[i]);
                top_mp[recipes[i]]++;
            }
        }
        queue<string>q;
        for(auto &it:supplies){
           for(auto &i: nie_mp[it]){
            if(--top_mp[i] == 0){
                q.push(i);
            }
           }
        }
        vector<string>ans;
        while(!q.empty()){
            string item=q.front();
             q.pop();
             ans.push_back(item);
            for(auto &i: nie_mp[item]){
            if(--top_mp[i] == 0){
                q.push(i);
            }
           }
        }
        return ans;

    }
};