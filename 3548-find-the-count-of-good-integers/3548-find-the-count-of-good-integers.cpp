class Solution {
public:
    vector<string> generatedNumbers;  // Store all generated numbers as strings
    unordered_map<int, long long> factorialMemo;  // Memoization for factorials

    // Optimized factorial calculation with memoization
    long long calculateFactorial(int size) {
        if (factorialMemo.find(size) != factorialMemo.end()) {
            return factorialMemo[size];
        }
        long long factorial = 1;
        for (int i = 1; i <= size; i++) {
            factorial *= i;
        }
        return factorialMemo[size] = factorial;
    }

    // Function to generate numbers with the given conditions
    void generateNumbers(int remainingDigits, string currentNumber, bool isOdd, string prefix, int startDigit) {
        if (remainingDigits == 0) {
            if (isOdd) {
                prefix.erase(prefix.begin());  // Remove the first digit if the number is odd
            }
            generatedNumbers.push_back(currentNumber + prefix);
            return;
        }
        for (char digit = (startDigit == 0) ? '1' : '0'; digit <= '9'; digit++) {
            generateNumbers(remainingDigits - 1, currentNumber + digit, isOdd, digit + prefix, 1);
        }
    }

    long long countGoodIntegers(int n, int k) {
        // Generate all possible numbers based on the constraints
        generateNumbers((n + 1) / 2, "", n % 2, "", 0);

        long long result = 0;
        set<vector<int>> uniqueDigitFrequencies;  // Set to track unique digit frequencies

        for (auto& number : generatedNumbers) {
            // Check if the number is divisible by k
            if (stol(number) % k == 0) {
                vector<int> digitFrequency(10, 0);  // Frequency array for digits
                int totalDigits = 0, permutationCount = 1;

                // Calculate the frequency of each digit in the current string
                for (char digit : number) {
                    digitFrequency[digit - '0']++;
                }

                // Skip already processed frequencies to avoid redundant calculations
                if (uniqueDigitFrequencies.find(digitFrequency) != uniqueDigitFrequencies.end()) {
                    continue;
                }
                uniqueDigitFrequencies.insert(digitFrequency);

                // Count the non-zero digits and calculate the permutations
                for (int digit = 1; digit <= 9; digit++) {
                    if (digitFrequency[digit] > 0) {
                        totalDigits += digitFrequency[digit];
                        permutationCount *= calculateFactorial(digitFrequency[digit]);
                    }
                }

                long long zeroDigitCount = 0;
                if (digitFrequency[0] > 0) {
                    totalDigits += digitFrequency[0];
                    zeroDigitCount = calculateFactorial(totalDigits - 1) / (permutationCount * calculateFactorial(digitFrequency[0] - 1));
                    permutationCount *= calculateFactorial(digitFrequency[0]);
                }

                result += (calculateFactorial(totalDigits) / permutationCount) - zeroDigitCount;  // Add to the result
            }
        }

        return result;
    }
};
