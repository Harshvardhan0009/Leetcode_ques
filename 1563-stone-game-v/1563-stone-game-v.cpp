class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n + 1);
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + a[i];

        function<int(int,int)> dfs = [&](int l, int r) {
            if (l == r) return 0;
            if (dp[l][r] != -1) return dp[l][r];

            int ans = 0;

            for (int k = l; k < r; k++) {
                int left = pre[k + 1] - pre[l];
                int right = pre[r + 1] - pre[k + 1];

                if (left < right)
                    ans = max(ans, left + dfs(l, k));
                else if (right < left)
                    ans = max(ans, right + dfs(k + 1, r));
                else
                    ans = max({ans, left + dfs(l, k),
                                    right + dfs(k + 1, r)});
            }

            return dp[l][r] = ans;
        };

        return dfs(0, n - 1);
    }
};