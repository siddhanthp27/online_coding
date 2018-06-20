#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int left_child(int i){
  return 2 * i + 1;
}

int right_child(int i){
  return 2 * i + 2;
}

void max_heapify(int a[], int i, int n){
  int largest;
  largest = i;
  int left, right;
  left = left_child(i);
  right = right_child(i);
  if (left < n && a[left] > a[largest] ){
    largest = left;
  }
  if (right < n && a[right] > a[largest] ){
    largest = right;
  }
  if (largest != i){
    int temp = a[largest];
    a[largest] = a[i];
    a[i] = temp;
    max_heapify(a, largest, n);
  }
}

// void it_max_heapify(int a[], int i){
//   int largest = i;
//   int left, right;
//   while (1){
//     largest = i;
//     left = left_child(i);
//     right = right_child(i);
//     if (a[left] > a[largest]){
//       largest = left;
//     }
//     if (a[right] > a[largest]){
//       largest = right;
//     }
//     if (largest != i){
//       int temp = a[largest];
//       a[largest] = a[i];
//       a[i] = a[largest];
//       i = largest;
//     }
//     else{
//       break;
//     }
//   }
// }

void build_heap(int a[], int n){
  for(int i = n/2; i >=0 ; i--){
    max_heapify(a, i, n);
  }
}

void heap_sort(int a[], int n){
  build_heap(a, n);
  int N = n;
  for (int i = N-1; i > 0; i--){
    int temp = a[0];
    a[0] = a[i];
    a[i] = temp;
    n--;
    max_heapify(a, 0, n);
  }
}

int main(){
  int a[10];
  int n = 10;
  for (int i = 0; i < n; i++){
    a[i] = n - i;
  }
  heap_sort(a, n);
  for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
