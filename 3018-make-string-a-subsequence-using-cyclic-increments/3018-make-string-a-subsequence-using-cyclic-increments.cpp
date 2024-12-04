class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j=0;
        for(int i=0;i<str1.size();i++){
            if(j == str2.size())break;
            cout<<str1[i]<<" "<<str2[j]<<endl;;
            if(str1[i] == str2[j]){
                j++;
                continue;
            }
            if( str1[i]+1 == str2[j]  || (str1[i] == 'z' and str2[j] == 'a')){
                j++;
            }
        }
        cout<<j<<endl;
        return (j == str2.size());
    }
};