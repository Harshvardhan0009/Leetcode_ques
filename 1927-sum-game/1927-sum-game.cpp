class Solution {
public:
    bool sumGame(string num) {
        int sum = 0, q = 0;
        int n = num.size();

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') q++;
            else sum += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') q--;
            else sum -= num[i] - '0';
        }
        if (q % 2)
            return true;

        return sum != -9 * q / 2;
    }
};