class Solution {
public:
    double champagneTower(int p, int query_row, int query_glass) {
        vector<vector<double>> dp(120, vector<double>(120, 0.0));
        // dp[1][0]->dp[0][0]
        // dp[0][1]->dp[0][0]
        // dp[1][0]->dp[0][1]
        // dp[1][1]->dp[1][0]+dp[0][1]
        // dp[1][2]->dp[0][1]
        // dp[i][j]->dp[i-1][j]+dp[i-1][j+1]
        dp[0][0] = p;
        for (int row = 1; row <=100; row++) {
            for (int clm = 0; clm <=100; clm++) {
                if (clm == 0) {
                    dp[row][clm] = max(0.00, ((dp[row - 1][clm] - 1) / 2));

                } else
                    dp[row][clm] = max(0.00, ((dp[row - 1][clm] - 1) / 2)) +
                                   max(0.00, ((dp[row - 1][clm - 1] - 1) / 2));
            }
        }
        // for(int i=0;i<10;i++){
        //     for(int j=0;j<10;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return (dp[query_row][query_glass] >= 1) ? 1.00000
                                                 : dp[query_row][query_glass];
    }
};