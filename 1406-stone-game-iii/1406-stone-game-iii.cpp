class Solution {
public:
    // int stoneGame(vector<int>& dp, const vector<int>& stoneValue, int i) {
    //     int n = stoneValue.size();

    //     if (i >= n)
    //         return 0;

    //     if (dp[i] != INT_MAX)
    //         return dp[i];

    //     int takeOne = stoneValue[i] - stoneGame(dp, stoneValue, i + 1);

    //     int takeTwo = INT_MIN;
    //     if (i + 1 < n)
    //         takeTwo = stoneValue[i] + stoneValue[i + 1]
    //                 - stoneGame(dp, stoneValue, i + 2);

    //     int takeThree = INT_MIN;
    //     if (i + 2 < n)
    //         takeThree = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2]
    //                   - stoneGame(dp, stoneValue, i + 3);

    //     return dp[i] = max({takeOne, takeTwo, takeThree});
    // }

    // string stoneGameIII(vector<int>& stoneValue) {
    //     vector<int> dp(stoneValue.size(), INT_MAX);

    //     int value = stoneGame(dp, stoneValue, 0);

    //     if (value > 0)
    //         return "Alice";
    //     else if (value < 0)
    //         return "Bob";
    //     else
    //         return "Tie";
    // }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            dp[i] = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        else
            return "Tie";
    }
};