// User function Template for Java

class Solution {
    public ArrayList<Integer> findSubarray(int arr[]) {
        // code here
        ArrayList<Integer> list = new ArrayList<>();

        int n = arr.length;
        
        boolean isNegative = true;
        
        int MaxSum = Integer.MIN_VALUE;
        int sum = 0;
        
        int subStart = -1;
        int subEnd = -1;
        int Start = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i]>=0){
                sum+=arr[i];
                if(sum>MaxSum){
                    MaxSum = sum;
                    subStart = Start;
                    subEnd = i;
                }else if(sum==MaxSum && Start==subStart){
                    subEnd = i;
                }
            }else{
                Start = i+1;
                sum=0;
            }
            if(arr[i]>=0) isNegative = false;
        }
        
        if(isNegative){
            list.add(-1);
            return list;
        }
        
        for(int i=subStart; i<=subEnd; i++){
            list.add(arr[i]);
        }

        return list;
    }
}
