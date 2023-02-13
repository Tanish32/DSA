#include<stdio.h>
#include<stdlib.h>

//find last occurence
int nextIndex(int arr[], int start_idx, int end_idx, int target){
    int result = -1;
    while(end_idx >= start_idx){
        int mid = start_idx + (end_idx - start_idx)/2;

        if(arr[mid] == target){
            result = mid;
            start_idx = mid+1;
        }
        else if(arr[mid] > target)
            end_idx = mid-1;
        else
            start_idx = mid+1;
    }
    return result+1;
}

int countUnique(int arr[], int n){
    int i = 0;
    int count = 0;
    while(i < n){
        i = nextIndex(arr, i, n-1, arr[i]);
        if(i==0){
            return(0);
        }
        count++;
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",  &arr[i]);
    }
    printf("%d", countUnique(arr, n)); 
}
