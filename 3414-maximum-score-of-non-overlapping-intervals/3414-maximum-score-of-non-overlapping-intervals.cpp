class Solution {
public:
    using P=pair<long long,vector<int>>;
    vector<vector<P>> dp;
    vector<vector<int>> a;
    int n;
    P solve(int i,int k){
        if(i>=n||k==0) return {0,{}};
        if(dp[i][k].first!=-1) return dp[i][k];
        P skip=solve(i+1,k);
        int l=i+1,r=n;
        while(l<r){
            int m=(l+r)/2;
            if(a[m][0]>a[i][1]) r=m;
            else l=m+1;
        }
        P take=solve(l,k-1);
        take.first+=a[i][2];
        take.second.push_back(a[i][3]);
        sort(take.second.begin(),take.second.end());
        if(skip.first>take.first||(skip.first==take.first&&skip.second<take.second))
            return dp[i][k]=skip;
        return dp[i][k]=take;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n=intervals.size();
        a.resize(n);
        for(int i=0;i<n;i++)
            a[i]={intervals[i][0],intervals[i][1],intervals[i][2],i};
        sort(a.begin(),a.end());
        dp.assign(n,vector<P>(5,{-1,{}}));
        return solve(0,4).second;
    }
};