#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void printRepeating(int arr[], int size)
{
  int i;
  printf("The repeating elements are: \n");
  for (i = 0; i < size; i++)
  {
    // cout<<"i: "<<i<<" arr[i]: "<<arr[i]<<" arr[ abs(arr[i])]: "<<arr[abs(arr[i])]<<"\n";
    if (arr[abs(arr[i])] >= 0)
      arr[abs(arr[i])] = -arr[abs(arr[i])];
    else
      printf(" %d ", abs(arr[i]));
  }
}
 
int main()
{
  int arr[] = {1, 2, 3, 1, 3, 6, 9};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
  getchar();
  return 0;
}