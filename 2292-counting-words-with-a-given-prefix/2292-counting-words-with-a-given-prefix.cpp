class Solution {
public:
bool isprfix(string pref,string word){
    int sz=pref.size();
    //if pref lenght is bigger than word lenght is imposible to be prfix
    if(sz>word.size())return false;
    for(int i=0;i<sz;i++){
        // if any char in lenght i not equal each Other return false 
        if(pref[i]!=word[i])return false;
    }
    //finaly return true if all pref is prfix into word
    return true;
}
    int prefixCount(vector<string>& words, string pref) {
        int sz=words.size();
        int cnt=0;
        for(int i=0;i<sz;i++){
            //check if the pref string is prfix into words[i]
            if(isprfix(pref,words[i])){
                //increase cnt -> 1
                cnt++;
            }
        }
        return cnt;
    }
};