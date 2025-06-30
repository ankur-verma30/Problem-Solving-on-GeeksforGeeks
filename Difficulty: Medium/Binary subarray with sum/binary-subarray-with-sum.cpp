class Solution {
  public:
    int solve(vector<int>&arr,int goal){
        if(goal<0) return 0;
        
        int left=0,count=0,sum=0,n=arr.size();
        
        for(int right=0;right<n;right++){
            sum+=arr[right];
            
            while(sum>goal){
                sum-=arr[left];
                left++;
            }
            count+=(right-left+1);
            
        }
        
        return count;
    }
    int numberOfSubarrays(vector<int>& arr, int target) {
       return solve(arr,target)-solve(arr,target-1);
    }
};