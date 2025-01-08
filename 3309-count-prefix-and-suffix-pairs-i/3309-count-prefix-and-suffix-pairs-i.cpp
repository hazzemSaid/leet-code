class Solution {
public:
bool isprfix(string s,string os){
    for(int i=0;i<s.size();i++){
        if(s[i] != os[i])return false;
    }
    return true;

}
bool issufix(string s,string os){
        reverse(os.begin(),os.end());
        reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i] != os[i])return false;
    }
    return true;
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
            for(int i=0;i<words.size();i++){
                for(int j=i+1;j<words.size();j++){
                    if(isprfix(words[i],words[j]) and issufix(words[i],words[j]) ){
                        ans++;
                    }
                }
            }
            return ans;
    }
};