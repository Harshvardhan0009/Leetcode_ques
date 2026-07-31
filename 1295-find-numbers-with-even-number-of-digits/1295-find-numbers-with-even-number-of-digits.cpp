class Solution {
public:
    bool size(int num){
        int count=0;
        while(num!=0){
            num=num/10;
            count++;
        }

        if(count%2==0){
            return true;
        }
        else{
            return false;
        }
        
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(size(nums[i])==true){
                count++;
            }
        }
        return count;
    }
};