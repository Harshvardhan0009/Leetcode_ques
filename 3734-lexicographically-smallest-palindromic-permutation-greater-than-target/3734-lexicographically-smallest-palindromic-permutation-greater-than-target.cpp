class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), h = n / 2;
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (mid) return "";
                mid = 'a' + i;
            }
            cnt[i] /= 2;
        }
        
        auto build = [&](string left) {
            string right = left;
            reverse(right.begin(), right.end());
            return left + (n % 2 ? string(1, mid) : "") + right;
        };
        
        int i = 0;
        
        while (i < h && cnt[target[i] - 'a']) {
            cnt[target[i] - 'a']--;
            i++;
        }
        
        if (i == h) {
            string left = target.substr(0, h);
            string ans = build(left);
            if (ans > target) return ans;
        }
        
        for (int j = i; j >= 0; j--) {
            if (j < i)
                cnt[target[j] - 'a']++;
            
            int x = target[j] - 'a';
            
            for (int c = x + 1; c < 26; c++) {
                if (!cnt[c]) continue;
                
                cnt[c]--;
                
                string left = target.substr(0, j);
                left += char('a' + c);
                
                for (int k = 0; k < 26; k++)
                    left += string(cnt[k], 'a' + k);
                
                return build(left);
            }
        }
        
        return "";
    }
};