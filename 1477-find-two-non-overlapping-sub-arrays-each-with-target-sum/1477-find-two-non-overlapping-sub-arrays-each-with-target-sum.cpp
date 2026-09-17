class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size(),sum=0,ans=INT_MAX;
        map<int,int> mp;
        vector<int> best(n,INT_MAX);
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.count(sum-target)){
                int l=mp[sum-target]+1;
                int len=i-l+1;
                if(l>0 && best[l-1]!=INT_MAX)
                    ans=min(ans,len+best[l-1]);
                if(i==0) best[i]=len;
                else best[i]=min(best[i-1],len);
            }else{
                best[i]=(i?best[i-1]:INT_MAX);
            }
            mp[sum]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};