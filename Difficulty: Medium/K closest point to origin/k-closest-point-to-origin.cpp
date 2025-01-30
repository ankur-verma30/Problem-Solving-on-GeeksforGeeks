//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;




// } Driver Code Ends
//User function template for C++

// points : 2-d vector containing the (x, y) points
// K : number of closest points that we need to find 
// return 2d vector containing the k points in increasing order of distance from origin

class Solution{
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         int n = points.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            int xcord = points[i][0];
            int ycord = points[i][1];

            double distance = sqrt(xcord * xcord + ycord * ycord);

            pq.push({distance, {xcord, ycord}});
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto it = pq.top();
            vector<int> temp = {it.second.first, it.second.second};
            ans.push_back(temp);
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
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<vector<int>> p, res;
        
        for(int i = 0 ; i < n ; ++ i ) {
            vector<int> vec(2);
            cin >> vec[0] >> vec[1];
            p.push_back(vec);
        }
        Solution obj;
        res = obj.kClosest(p, k);
        
        for(int i = 0 ; i < k ; ++ i ) {
            cout << res[i][0] << " " << res[i][1] << " ";
        }
        
        cout << "\n";
        
    
cout << "~" << "\n";
}
}
// } Driver Code Ends