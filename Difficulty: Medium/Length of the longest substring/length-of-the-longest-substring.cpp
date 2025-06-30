class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        int maxLength=0,left=0;
        unordered_set<char>st;
        
        for(int right=0;right<s.length();right++){
            if(st.count(s[right])<1) st.insert(s[right]);
            
            else if(st.count(s[right])){
                while(st.count(s[right])){
                    st.erase(s[left]);
                    left++;
                }
                st.insert(s[right]);
            }
             maxLength=max(maxLength,(int)st.size());
        }
         maxLength=max(maxLength,(int)st.size());
         return maxLength;
    }
};