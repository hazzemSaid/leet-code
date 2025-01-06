class Solution {
public:
    vector<int> minOperations(string boxes) {
        int sz = boxes.size(); // Get the size of the input string `boxes`
        
        vector<vector<int>> prfix, sufix; // To store prefix and suffix indices of '1's
        vector<int> ones; // Temporary vector to store indices of '1's

        // Build the prefix array
        for (int i = 0; i < sz; i++) {
            prfix.push_back(ones); // Store the current prefix `ones` for index `i`
            if (boxes[i] == '1') { // If the current box contains a ball ('1')
                ones.push_back(i); // Add its index to `ones`
            }
        }

        ones.clear(); // Clear the `ones` vector for reuse

        // Build the suffix array
        for (int i = sz - 1; i >= 0; i--) {
            sufix.push_back(ones); // Store the current suffix `ones` for index `i`
            if (boxes[i] == '1') { // If the current box contains a ball ('1')
                ones.push_back(i); // Add its index to `ones`
            }
        }

        reverse(sufix.begin(), sufix.end()); // Reverse the suffix array to align with prefix

        vector<int> ans; // To store the final result

        // Calculate the minimum number of operations for each box
        for (int i = 0; i < sz; i++) {
            int cnt = 0; // Counter to track the operations needed for the current box

            // Add operations from prefix for box `i`
            for (auto &it : prfix[i]) {
                cnt += i - it; // Calculate the distance and add to `cnt`
            }

            // Add operations from suffix for box `i`
            for (auto &it : sufix[i]) {
                cnt += it - i; // Calculate the distance and add to `cnt`
            }

            ans.push_back(cnt); // Store the total operations for box `i`
        }

        return ans; // Return the result
    }
};
