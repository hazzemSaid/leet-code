class Solution {
public:
bool valid(char a,char b){
    //build the validation function for check if the first char and end char are (vowel letters)
    bool l=false,k=false;
    if(a == 'a' || a=='e' || a=='i' || a=='o' || a=='u')l=true;
    if(b == 'a' || b=='e' || b=='i' || b=='o' || b=='u')k=true;
    // return true if and only if both are true
    return (k&l);
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int sz=words.size();
        //make the prfix sum to calculate the words ith if valid is true 
        vector<int>prfix(sz+1,0);
        for(int i=0;i<sz;i++){
            char firstch=words[i][0];
            char endch=words[i][words[i].size()-1];
            if(valid(firstch,endch)){
                prfix[i+1]=1;
            }
            if(i!=0)
            prfix[i+1]+=prfix[i];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            //make the two part from (r+1 - l) from prfix i calculate before
            ans.push_back(prfix[r+1]-prfix[l]);
        }
        return ans;
    }
};