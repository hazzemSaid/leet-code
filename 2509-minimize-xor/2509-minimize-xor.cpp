class Solution {
public:
    // Function to count the number of 1s in the binary representation of a number
    int onesInNumber(int num) {
        int ones = 0;
        while (num) {
            ones += num & 1; // Increment if the last bit is 1
            num >>= 1;       // Right shift to process the next bit
        }
        return ones;
    }

    int minimizeXor(int num1, int num2) {
        int ones1 = onesInNumber(num1);
        int ones2 = onesInNumber(num2);

        // If the number of 1s in num1 and num2 are the same, return num1 directly
        if (ones1 == ones2) return num1;

        int res = 0;

        // Case 1: num1 has more 1s than num2
        if (ones1 > ones2) {
            // We need to reduce the number of 1s in num1
            for (int i = 31; i >= 0 && ones2 > 0; i--) {
                if (num1 & (1 << i)) { // Check if the ith bit is set in num1
                    res |= (1 << i);   // Set the ith bit in the result
                    ones2--;
                }
            }
        } 
        // Case 2: num1 has fewer 1s than num2
        else {
            // Start with num1 and add more 1s where needed
            res = num1;
            ones2 -= ones1; // Remaining 1s to add
            for (int i = 0; i < 32 && ones2 > 0; i++) {
                if ((num1 & (1 << i)) == 0) { // Check if the ith bit is not set in num1
                    res |= (1 << i);         // Set the ith bit in the result
                    ones2--;
                }
            }
        }

        return res;
    }
};
