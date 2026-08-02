class Solution {
public:
    int t[501][501];

    int solve(vector<int>& piles, int i, int j) {

        // No piles left
        if (i > j)
            return 0;

        // Already computed
        if (t[i][j] != -1)
            return t[i][j];

        // If I pick the left pile
        int take_i = piles[i] + min(
            solve(piles, i + 2, j),      // Bob picks left
            solve(piles, i + 1, j - 1)   // Bob picks right
        );

        // If I pick the right pile
        int take_j = piles[j] + min(
            solve(piles, i, j - 2),      // Bob picks right
            solve(piles, i + 1, j - 1)   // Bob picks left
        );

        return t[i][j] = max(take_i, take_j);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        memset(t, -1, sizeof(t));

        int totalSum = 0;
        for (int x : piles)
            totalSum += x;

        int alice = solve(piles, 0, n - 1);
        int bob = totalSum - alice;

        return alice > bob;
    }
};