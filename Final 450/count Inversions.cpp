// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.

long long int merge(long long arr[], long long l, long long mid, long long r){
    
    long long int inv = 0, n1 = mid - l + 1, n2 = r - mid;
    long long a[n1], b[n2];
    for(long long i = 0; i<n1; i++){
        a[i] = arr[l+i];
    }
    for(long long i = 0; i<n2; i++){
        b[i] = arr[mid + i + 1];
    }
    
    long long i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if (a[i] <= b[j]){
            arr[k] = a[i];
            k++; i++;
        }
        else{
            inv += n1 - i;
            arr[k] = b[j];
            j++; k++;
        }
    }
    
    while(i < n1){
        arr[k] = a[i];
        i++;k++;
    }
    
    while(j < n2){
        arr[k] = b[j];
        j++; k++;
    }
    
    return inv;
}

long long int mergeSort(long long arr[], long long l, long long r){
    long long int ans = 0;
    if (l < r){
        long long mid = l + (r-l)/2;
        ans += mergeSort(arr, l, mid);
        ans += mergeSort(arr, mid + 1, r);
        ans += merge(arr, l, mid, r);
    }
    
    return ans;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr, 0, N-1);
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends