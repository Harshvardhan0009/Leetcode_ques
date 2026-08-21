class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1, hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        auto count = [&](long long x) {
            long long res = 0;
            int n = coins.size();
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) {
                        bits++;
                        long long g = gcd(lcm, (long long)coins[i]);
                        if (lcm > x / (coins[i] / g)) {
                            ok = false;
                            break;
                        }
                        lcm = lcm / g * coins[i];
                    }
                }
                if (!ok || lcm > x) continue;
                if (bits & 1) res += x / lcm;
                else res -= x / lcm;
            }
            return res;
        };
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};