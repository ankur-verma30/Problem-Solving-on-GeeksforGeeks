class Solution {
  public:
    int solve(vector<int>&arr,int target){
        if(target==0) return 0;
        unordered_map<int,int>mpp;
        int left=0,count=0,n=arr.size();
        
        for(int right=0;right<n;right++){
            mpp[arr[right]]++;
            
            while(mpp.size()>target){
                mpp[arr[left]]--;
                if(mpp[arr[left]]==0) mpp.erase(arr[left]);
                left++;
            }
            
            count+=(right-left+1);
        }
        return count;
    }
    int exactlyK(vector<int> &arr, int k) {
       
       return solve(arr,k)-solve(arr,k-1);
        
    }
};