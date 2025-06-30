class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
        vector<int>freq(26,0);
        int maxFreq=0,n=s.length(),left=0,maxLength=0;
        
        for(int right=0;right<n;right++){
            freq[s[right]-'A']++;
            maxFreq=max(maxFreq,freq[s[right]-'A']);
            if((right-left+1-maxFreq)>k){
                int currMax=0;
                freq[s[left]-'A']--;
                for(const auto &it:freq) currMax=max(currMax,it);
                if(currMax<=maxFreq) maxFreq=currMax;
                left++;
            }
            else{
                maxLength=max(maxLength,right-left+1);
            }
        }
        
        return maxLength;
    }
};