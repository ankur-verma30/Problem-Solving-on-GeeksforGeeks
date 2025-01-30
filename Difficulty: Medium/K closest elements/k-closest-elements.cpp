//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
     priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>
            pq(cmp);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if(arr[i]==x) continue;
            int diff = abs(x - arr[i]);
            pq.push({arr[i], diff});
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            auto it = pq.top();
            ans.push_back(it.first);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends