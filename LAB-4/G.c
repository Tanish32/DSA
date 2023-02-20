#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int find_max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort on an array based on a given digit
void counting_sort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    // Counting occurences of each digit
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Updating count array to store actual position of each digit in output
    // array
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Placing each element in its sorted position in output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copying the sorted array from output to arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform radix sort on an array
void radix_sort(int arr[], int n)
{
    int max = find_max(arr, n);

    // Performing counting sort on each digit from least significant to most
    // significant
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(arr, n, exp);
    }
}

// Example usage
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    radix_sort(arr, n);
    return 0;
}
