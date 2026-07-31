class Solution {
public:
    int minimumPushes(string word) {
        int cost=0;
        int ans=0;
        vector<int> freq(26,0);
        for(int i=0; i<word.size(); i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i=0; i<26; i++){
            if(freq[i]==0){
                break;
            } 
            cost = (i/8)+1;
            ans += freq[i]*cost;
        }
        return ans;
    }
};