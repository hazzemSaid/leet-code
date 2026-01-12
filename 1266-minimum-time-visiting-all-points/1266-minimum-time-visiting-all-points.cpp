class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cnt = 0;
        int sz = points.size();
        for (int i = 1; i < sz; i++) {
            cnt += min(max(abs(points[i][0] - points[i - 1][0]),
                           abs(points[i][1] - points[i - 1][1])),
                       int(sqrt((pow(points[i][0] - points[i - 1][0], 2)) +
                                (pow(points[i][1] - points[i - 1][1], 2)))));
        }
        return cnt;
    }
};