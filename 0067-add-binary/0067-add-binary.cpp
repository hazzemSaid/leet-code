class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int curr = 0;
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            if (a[i] == '1' and b[i] == '1') {
                if (curr)
                    sum += '1';
                else
                    sum += '0';
                curr = 1;
            } else if (a[i] == '0' and b[i] == '0') {
                if (curr) {
                    curr = 0, sum += '1';
                } else
                    sum += '0';
            } else if (a[i] == '0' || b[i] == '0') {
                if (curr) {
                    curr = 1, sum += '0';
                } else
                    sum += '1';
            }
        }
        if (a.size() < b.size()) {
            for (int i = a.size(); i < b.size(); i++) {
                if (b[i] == '1') {
                    if (curr) {
                        sum += '0';
                    } else
                        sum += '1';
                } else {
                    if (curr) {
                        sum += '1';
                    } else
                        sum += '0';
                    curr = 0;
                }
            }
        }
        if (a.size() > b.size()) {
            for (int i = b.size(); i < a.size(); i++) {
                if (a[i] == '1') {
                    if (curr) {
                        sum += '0';
                    } else
                        sum += '1';
                } else {
                    if (curr) {
                        sum += '1';
                    } else
                        sum += '0';
                    curr = 0;
                }
            }
        }
        reverse(sum.begin(), sum.end());
        if (curr) {
            sum = '1' + sum;
        }
        return sum;
    }
};