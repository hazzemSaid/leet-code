class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //set for check if number still there  in O(1)
        set<int>t;
        //size if arrays
        int n=A.size();

        vector<int>ans;

        for(int i =1;i<=n;i++)t.insert(i); // insert all number from 1 to n

        for(int i=n-1;i>=0;i--){
            //push the number of unique number in t
            ans.push_back(t.size());

            // if t have the A[i] erase it
            if(t.find(A[i]) != t.end()){
                t.erase(A[i]);
            }

            // if t have the B[i] erase it
            if(t.find(B[i]) != t.end()){
                t.erase(B[i]);
            }
        }
        //reverse the ans 
       reverse(ans.begin(),ans.end());
       return ans;

    }
};