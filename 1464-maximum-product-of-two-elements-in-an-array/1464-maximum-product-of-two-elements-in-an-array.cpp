class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lar1=0;
        int lar2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>lar1){
                lar2=lar1;
                lar1=nums[i];
            }
            else if(nums[i]>lar2){
                lar2=nums[i];
            }
        }
        return (lar1-1) * (lar2-1);
    }
};