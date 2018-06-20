#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int count_collatz(int n){
  int count = 0;
  while(n != 1){
    printf("%d\n", n);
    count++;
    if (n%2){
      n = 3 * n + 1;
    }
    else{
      n = n / 2;
    }
  }
  return count;
}

int main(){
  int lower, upper;
  int max_count = 0, temp_count;
  scanf("%d %d", &lower, &upper);
  for(int i = lower; i <= upper; i++){
    temp_count = count_collatz(i);
    if (max_count < temp_count){
      max_count = temp_count;
    }
  }
  printf("max_count = %d\n", max_count + 1);
  return 0;
}
