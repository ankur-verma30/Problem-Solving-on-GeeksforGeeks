class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
          priority_queue<int ,vector<int>, greater<int>>pq;
       
       for(int i=0;i<n;i++){
           pq.push(arr[i]);
       }
       
        int sum=0;
       while(pq.size()>1){
       int n1=pq.top();
        pq.pop();
        int n2=pq.top();
        pq.pop();
        int temp=n1+n2;
        sum+=temp;
        pq.push(temp);
       }
       
       return sum;
    }
};