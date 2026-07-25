class Solution {
public:
    int maxProduct(int a) {
        long long int m = INT_MIN;
        long long int n = INT_MIN;
        int x = a;
        while(x>0){
            int t = x%10;
        
            if(t>m){
                n = m;
                m = t;
            }
            else if(t > n){
                n=t;
            }

            x=x/10;

        }

        return m*n;
    }
};