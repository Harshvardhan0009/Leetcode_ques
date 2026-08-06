class Solution {
public:

    int calculate(int i){
        int prod=1;
        while(i!=0){
            int x = i%10;
            i = i/10;
            prod*=x;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(true){
            if(calculate(i)%t==0){
                break;
            }
            i++;
        }
        return i;
    }
};