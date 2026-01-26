class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        vector<vector<int>> narr;
        int minn = INT_MAX;
        for (int i = 0; i < sz - 1; i++) {
            minn = min(minn, arr[i + 1] - arr[i]);
        }
        for (int i = 0; i < sz - 1; i++) {
            if (arr[i + 1] - arr[i] == minn)
                narr.push_back({arr[i], arr[i + 1]});
        }
        return narr;
    }
};