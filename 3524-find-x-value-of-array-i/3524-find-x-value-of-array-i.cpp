class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k),dp(k);
        for(int x:nums){
            vector<long long> ndp(k);
            int rem=x%k;
            ndp[rem]++;
            for(int r=0;r<k;r++)
                ndp[(r*rem)%k]+=dp[r];
            for(int r=0;r<k;r++){
                dp[r]=ndp[r];
                ans[r]+=dp[r];
            }
        }
        return ans;
    }
};