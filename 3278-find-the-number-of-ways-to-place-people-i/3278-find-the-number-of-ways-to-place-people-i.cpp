class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // شرط "A أعلى يسار B"
                if (!(x1 <= x2 && y1 >= y2)) continue;

                int bx = min(x1, x2), ex = max(x1, x2);
                int by = min(y1, y2), ey = max(y1, y2);

                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    int x = points[k][0], y = points[k][1];
                    if (bx <= x && x <= ex && by <= y && y <= ey) {
                        ok = false;
                        break;
                    }
                }
                if (ok) cnt++;
            }
        }
        return cnt;
    }
};
