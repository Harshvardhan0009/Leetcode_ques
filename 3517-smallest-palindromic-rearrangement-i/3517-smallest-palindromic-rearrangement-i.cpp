class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        string left = "";
        string middle = "";
        //here we will automatically get the sorted string because the loop itself is going in the alphabeticall order
        for(int i=0; i<26; i++){
            char ch = 'a'+i;
            for(int j=0; j<freq[i]/2; j++){
                left+=ch;
            }
            if(freq[i]%2==1){
                middle=ch;
            }
        }
        string right = left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
};