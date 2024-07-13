//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         
         int arr1[mid - l + 1];
         int arr2[r - mid];
         int n = mid - l + 1;
         int m = r - mid;
         for(int i = 0; i < n; i++){
             arr1[i] = arr[l + i];
         }
         for(int j = 0; j< m; j++){
             arr2[j] = arr[mid + 1 + j];
         }
         
         int arr3[r - l + 1];
         int i = 0, j = 0, k = 0;
         
         while(i < n && j < m){
             
             if(arr1[i] < arr2[j]){
                 arr3[k++] = arr1[i++];
             }
             else{
                 arr3[k++] = arr2[j++];
             }
             
         }
         while(i < n){
            arr3[k++] = arr1[i++]; 
         }
         while(j < m){
            arr3[k++] = arr2[j++]; 
         }
         for(int s = 0; s< (r - l + 1); s++){
             arr[l + s] = arr3[s];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)  return;
        int m = l + (r - l)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l , m , r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends