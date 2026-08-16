class Solution {
public:

    bool check(vector<int> cnt) {
        if (cnt[1] == 0)
            return false;

        cnt[1]--;

        int turns = 1 + min(cnt[1], cnt[2]) * 2 + cnt[0];

        if (cnt[1] > cnt[2]) {
            cnt[1]--;
            turns++;
        }

        return turns % 2 == 1 && cnt[1] != cnt[2];
    }

    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);

        for (int x : stones)
            cnt[x % 3]++;

        vector<int> swapped = {cnt[0], cnt[2], cnt[1]};

        return check(cnt) || check(swapped);
    }
};