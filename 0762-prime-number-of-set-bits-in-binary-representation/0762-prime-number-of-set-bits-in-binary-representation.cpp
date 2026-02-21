class Solution {
public:
    set<int> primes;
    void sieve(int n) {

        // creation of boolean array
        vector<bool> prime(n + 1, true);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {

                // marking as false
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        for (int p = 2; p <= n; p++) {
            if (prime[p]) {
                primes.insert(p);
            }
        }
    }
    int countPrimeSetBits(int left, int right) {
        sieve(int(30));
        int res = 0;
        for (int i = left; i <= right; i++) {
            int cnt = 0;
            int num = i;
            while (num) {
                if (num % 2 == 1)
                    cnt++;
                num >>= 1;
            }
            if (primes.find(cnt) != primes.end())
                res++;
        }
        return res;
    }
};