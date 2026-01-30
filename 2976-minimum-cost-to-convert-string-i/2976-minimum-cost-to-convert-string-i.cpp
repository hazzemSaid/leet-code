class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        // Create a graph representation of character conversions
        vector<vector<pair<int, int>>> adjacencyList(26);

        // Populate the adjacency list with character conversions
        int conversionCount = original.size();
        for (int i = 0; i < conversionCount; i++) {
            adjacencyList[original[i] - 'a'].push_back(
                {changed[i] - 'a', cost[i]});
        }

        // Calculate shortest paths for all possible character conversions
        vector<vector<long long>> minConversionCosts(26, vector<long long>(26));
        for (int i = 0; i < 26; i++) {
            minConversionCosts[i] = dijkstra(i, adjacencyList);
        }

        // Calculate the total cost of converting source to target
        long long totalCost = 0;
        int stringLength = source.length();
        for (int i = 0; i < stringLength; i++) {
            if (source[i] != target[i]) {
                long long charConversionCost =
                    minConversionCosts[source[i] - 'a'][target[i] - 'a'];
                if (charConversionCost == -1) {
                    return -1;  // Conversion not possible
                }
                totalCost += charConversionCost;
            }
        }
        return totalCost;
    }

private:
    // Find minimum conversion costs from a starting character to all other
    // characters
    vector<long long> dijkstra(
        int startChar, const vector<vector<pair<int, int>>>& adjacencyList) {
        // Priority queue to store characters with their conversion cost, sorted
        // by cost
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            priorityQueue;

        // Initialize the starting character with cost 0
        priorityQueue.push({0, startChar});

        // Array to store the minimum conversion cost to each character
        vector<long long> minCosts(26, -1);

        while (!priorityQueue.empty()) {
            auto [currentCost, currentChar] = priorityQueue.top();
            priorityQueue.pop();

            if (minCosts[currentChar] != -1 &&
                minCosts[currentChar] < currentCost)
                continue;

            // Explore all possible conversions from the current character
            for (auto& [targetChar, conversionCost] :
                 adjacencyList[currentChar]) {
                long long newTotalCost = currentCost + conversionCost;

                // If we found a cheaper conversion, update its cost
                if (minCosts[targetChar] == -1 ||
                    newTotalCost < minCosts[targetChar]) {
                    minCosts[targetChar] = newTotalCost;
                    // Add the updated conversion to the queue for further
                    // exploration
                    priorityQueue.push({newTotalCost, targetChar});
                }
            }
        }
        // Return the array of minimum conversion costs from the starting
        // character to all others
        return minCosts;
    }
};