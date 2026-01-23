class Solution {
public:

bool isBad(int i, const vector<long long>& nums, const vector<int>& next, int n) {
    return next[i] < n && nums[i] > nums[next[i]];
}

    int minimumPairRemoval(vector<int>& input) {
    
        int n = input.size();

        // use long long to avoid overflow
        vector<long long> nums(input.begin(), input.end());

        vector<int> prev(n), next(n);
        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        set<pair<long long,int>> st;
        for (int i = 0; i + 1 < n; i++)
            st.insert({nums[i] + nums[i + 1], i});


        int badCount = 0;
        for (int i = 0; i + 1 < n; i++)
            if (isBad(i, nums, next, n)) badCount++;

        int ops = 0;

        while (badCount > 0) {
            ops++;

            auto [sum, i] = *st.begin();
            st.erase(st.begin());

            int j = next[i];

            // remove old pairs
            if (prev[i] >= 0)
                st.erase({nums[prev[i]] + nums[i], prev[i]});
            if (next[j] < n)
                st.erase({nums[j] + nums[next[j]], j});

            // remove old bad relations
            if (prev[i] >= 0 && nums[prev[i]] > nums[i]) badCount--;
            if (nums[i] > nums[j]) badCount--;
            if (next[j] < n && nums[j] > nums[next[j]]) badCount--;

            // merge safely
            nums[i] += nums[j];

            // relink
            next[i] = next[j];
            if (next[j] < n) prev[next[j]] = i;

            // add new pairs
            if (prev[i] >= 0) {
                st.insert({nums[prev[i]] + nums[i], prev[i]});
                if (nums[prev[i]] > nums[i]) badCount++;
            }
            if (next[i] < n) {
                st.insert({nums[i] + nums[next[i]], i});
                if (nums[i] > nums[next[i]]) badCount++;
            }
        }

        return ops;
    }
};