//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
      stack<string>st;
      int n=arr.size();
      
      for(int i=0;i<n;i++){
          if(arr[i]=="+"){
              int val1=stoi(st.top());
              st.pop();
              int val2=stoi(st.top());
              st.pop();
              st.push(to_string(val1+val2));
              continue;
          }
           else if(arr[i]=="*"){
              int val1=stoi(st.top());
              st.pop();
              int val2=stoi(st.top());
              st.pop();
              st.push(to_string(val1*val2));
               continue;
          }
          else if(arr[i]=="/"){
              int val1=stoi(st.top());
              st.pop();
              int val2=stoi(st.top());
              st.pop();
              st.push(to_string(val2/val1));
               continue;
          }
          else if(arr[i]=="-"){
              int val1=stoi(st.top());
              st.pop();
              int val2=stoi(st.top());
              st.pop();
              st.push(to_string(val2-val1));
               continue;
          }
          else st.push(arr[i]);
          
      }
      string res=st.top();
      return stoi(res);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends