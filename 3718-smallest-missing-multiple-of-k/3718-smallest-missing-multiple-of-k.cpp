class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> freq(nums.begin(),nums.end());
        for(int i=1; ; i++){
            int x = i*k;
            if(!freq.count(x)){
                return x;
            }
        }
    }
};