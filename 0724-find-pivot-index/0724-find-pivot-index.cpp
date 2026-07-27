class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0;
        int rightsum=0;
        int ans=-1;
        for(int i=0; i<nums.size(); i++){
            totalsum+=nums[i];
        }
        for(int i=nums.size()-1; i>=0; i--){
            int leftsum=totalsum-nums[i]-rightsum;
            if(leftsum==rightsum){
                ans=i;
            }
            rightsum+=nums[i];
        }
        return ans;
    }
};