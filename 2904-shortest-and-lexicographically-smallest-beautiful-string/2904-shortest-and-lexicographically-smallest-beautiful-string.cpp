class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, ones = 0;
        string ans = "";
        for (int r = 0; r < s.size(); r++) {
            ones += s[r] == '1';
            while (ones > k)
                ones -= s[l++] == '1';
            while (l <= r && s[l] == '0')
                l++;
            if (ones == k) {
                string cur = s.substr(l, r - l + 1);
                if (ans.empty() || cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans))
                    ans = cur;
            }
        }
        return ans;
    }
};