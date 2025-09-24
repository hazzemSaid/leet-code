class Solution {
public:
    string fractionToDecimal(int num, int d) {
        long long n = llabs((long long)num);
        long long den = llabs((long long)d);
        string ans = "";

        if (n == 0)
            return "0";
        if ((num < 0) ^ (d < 0))
            ans = "-" + ans;
        ans += to_string(n / den);

        long long rem = n % den;
        if (rem == 0)
            return ans;

        ans += ".";
        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {

                ans.insert(seen[rem], "(");
                ans += ")";
                break;
            }
            seen[rem] = ans.size();

            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }

        return (ans);
    }
};