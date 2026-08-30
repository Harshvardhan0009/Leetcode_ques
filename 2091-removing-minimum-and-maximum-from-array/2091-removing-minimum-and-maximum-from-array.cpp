class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;
            if (nums[i] > nums[mx])
                mx = i;
        }
        int left = min(mn, mx);
        int right = max(mn, mx);
        int ans = min({
            right + 1,
            n - left,
            left + 1 + n - right
        });
        return ans;
    }
};