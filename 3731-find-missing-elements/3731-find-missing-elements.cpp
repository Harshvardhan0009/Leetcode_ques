class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        unordered_set<int> freq;
        for(int i=0; i<nums.size(); i++){
            mn = min(nums[i],mn);
            mx = max(nums[i],mx);
            freq.insert(nums[i]);
        }
        vector<int> ans;
        for(int i=mn; i<=mx; i++){
            if(!freq.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};