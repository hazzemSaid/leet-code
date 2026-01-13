class Solution {
public:
    double msb(long double total, vector<vector<int>>& squares) {
        double l = 0.0, r = (1e9) + 1.0, res = 0.0;
        while (r - l > 1e-5) {
            long double m = (l + r) / 2.0;
            if (can(m, squares) < total / 2.00) {
                l = m;
                res = m;
            } else
                r = m;
        }
        return res;
    }
    long double can(long double m, vector<vector<int>>& squares) {
        long double area = 0.0;

        for (auto& it : squares) {
            double y = it[1];
            double l = it[2];

            if (m <= y)
                continue;
            else if (m >= y + l)
                area += l * l;
            else
                area += (m - y) * l;
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        long double total = 0;
        for (auto& it : squares) {
            total += (double)it[2] * it[2];
        }
        return msb(total, squares);
    }
};