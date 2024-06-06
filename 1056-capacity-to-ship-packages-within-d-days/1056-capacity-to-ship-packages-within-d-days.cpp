class Solution {
public:
    bool isPossible(vector<int> arr, int mid, int days){
        int capacity = 0, din = 1;
        for(int i = 0; i< arr.size(); i++){
            if((capacity + arr[i]) <= mid)
               capacity += arr[i];
            else{
                din++;
                if(din > days || arr[i]> mid)
                   return false;
                capacity = arr[i]; 
            }
            
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //sabse pahele sample space bana do
        int sum = 0;
        for(int i = 0; i<weights.size(); i++)
           sum += weights[i];
        int s = 0, e = sum, ans = -1;
        int mid = s + (e-s)/2;
        while(s <= e){
            if(isPossible(weights,mid, days)){
                 ans = mid;
                 e = mid -1;
            }
            else 
                 s = mid + 1;
            mid = s + (e -s)/2;
        }
        return ans;
    }
};