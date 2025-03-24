class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int,int>prf_meeting;
        int sz=meetings.size();
        int prvday=INT_MAX;
        for(int i=0;i<sz;i++){
            int start=meetings[i][0];
            int end=meetings[i][1];
            prf_meeting[start]+=1;
            prf_meeting[end+1]-=1;
            prvday=min(prvday,start);
        }
       int cnt=prvday-1;
       int prfsum=0;
       for(auto it:prf_meeting){
        int cur=it.first;
        if(prfsum == 0){cnt+=cur-prvday;}
        prvday=cur;
        prfsum+=it.second;
       }
       cnt+=days-prvday+1;
        return cnt;
    }
};