//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool static compare(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
       int n=start.size();
       int count=0,freeTime=-1;
       
       vector<pair<int,int>>meetings;
       for(int i=0;i<n;i++){
           meetings.push_back({start[i],end[i]});
       }
       
       
       sort(meetings.begin(),meetings.end(),compare);
       
       for(int i=0;i<n;i++){
           if(freeTime==-1 || freeTime<meetings[i].first){
               count++;
               freeTime=meetings[i].second;
           }
       }
       
       return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends