#include <stdio.h>
#include <stdlib.h>
int numberOfTurns(int arrLength, int arr[], int turn);

int main()
{
    // To get the input
    int arrLength, turn = 0;
    scanf("%d", &arrLength);
    int arr[arrLength];
    for (int i = 0; i < arrLength; i++)
    {
        scanf("%d", &arr[i]);
    }
    turn = numberOfTurns(arrLength, arr, turn); // no of turns
    // to get to 2 turns

    while (turn > 2)
    {
        for (int i = 1; i < arrLength; i++)
        {
            // adjacent swap
            if (arr[i - 1] > 0 && arr[i] < 0)
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        turn = 0;
        turn = numberOfTurns(arrLength, arr, turn);
    }
    // to print back the array
    printf("\n");
    for (int i = 0; i < arrLength; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
// To return number of turns
int numberOfTurns(int arrLength, int arr[], int turn)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (i > 0 && ((arr[i - 1] > 0 && arr[i] < 0) || (arr[i - 1] < 0 && arr[i] > 0)))
        {
            turn++;
        }
    }
    return turn;
}
