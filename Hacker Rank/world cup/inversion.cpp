#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
using namespace std;
int  _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
   number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;

    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;

  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];

     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }

  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];

  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

/* Driver progra to test above functions */
int arr[300], arr1[300];
int main(int argv, char** args)
{
  int n;
  //scanf("%d", &n);
  //for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

  n = 10;
  for(int i = 0; i < n; i++) arr[i] = i + 1;
  random_shuffle(arr, arr + n);

  for(int k = 0; k < n; k++) arr1[k] = arr[k];
  //printf("Arr = "); for(int k = 0; k < n; k++) printf("%d ", arr[k]); printf("\n");
  int mini, minj;
  int ini = mergeSort(arr, n);
  //printf("init = %d\n", ini);
  if(ini == 0) {printf("Cool Array\n"); return 0;}
  for(int i = 0; i < n - 1; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      for(int k = 0; k < n; k++) arr[k] = arr1[k];
      int tempp = arr[i];
      arr[i] = arr[j];
      arr[j] = tempp;
      int tc = mergeSort(arr, n);
      printf("i = %d j = %d tc= %d\n", i, j, tc);
      if(tc < ini)
      {
        ini = tc;
        mini = i;
        minj = j;
      }
    }
  }
  printf("%d %d\n", mini + 1, minj + 1);
  if(arr1[mini] == minj + 1 || arr1[minj] == mini + 1)
  {
    printf("True\n");
  }
  else
  {
    printf("False !! Wrong !! Arr = ");
    for(int k = 0; k < n; k++) printf("%d ", arr1[k]);printf("\n");
  }
  return 0;
}
