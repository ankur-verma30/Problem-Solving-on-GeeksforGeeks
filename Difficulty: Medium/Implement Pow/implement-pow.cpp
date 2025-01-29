//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
      
      int pow=e;
      if(e<0) e*=-1;
      double ans=1;
      while(e!=0){
          if(e%2){
              ans*=b;
              e=e-1;
          }
          else{
              b=b*b;
              e=e/2;
          }
      }
      
      if(pow<0)  return 1/ans;
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends