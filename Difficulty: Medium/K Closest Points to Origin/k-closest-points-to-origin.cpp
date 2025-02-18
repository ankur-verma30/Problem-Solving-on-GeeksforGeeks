//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  struct comparator{
    bool operator()(const pair<double, pair<int, int>>& a, const pair<double, pair<int, int>>& b) {
       return a.first < b.first; 
    } 
  };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,comparator>pq;
        
        for(const auto point:points){
            int x=point[0];
            int y=point[1];
            
            double distance=sqrt(x*x+y*y);
            pq.push({distance,{x,y}});
            if(pq.size()>k) pq.pop();
        }
        
        vector<vector<int>>res;
        
        while(!pq.empty()){
            auto temp=pq.top();
            int x=temp.second.first;
            int y=temp.second.second;
            res.push_back({x,y});
            pq.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends