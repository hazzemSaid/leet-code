class Solution {
public:
int maxincreasing(vector<int>&num){
    int cnt=1;
    int gcnt=1;
    for(int i=0;i<num.size()-1;i++){
        if(num[i]<num[i+1])cnt++;
        else cnt=1;
        gcnt=max(gcnt,cnt);
    }
    return gcnt;
}
int maxdec(vector<int>&num){
    int cnt=1;
    int gcnt=1;
    reverse(num.begin(),num.end());
    for(int i=0;i<num.size()-1;i++){
        if(num[i]<num[i+1])cnt++;
        else cnt=1;
        gcnt=max(gcnt,cnt);
    }
    return gcnt;
}
    int longestMonotonicSubarray(vector<int>& nums) {
        int ansc=maxincreasing(nums);
        int ansd=maxdec(nums);
        return max(ansc,ansd);
    }
};