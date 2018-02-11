#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long ner = 0;
long long swp = 0;

void swap(long long *a, long long *b){
  long long temp = *a;
  *a = *b;
  *b = temp;
}

int mod(long long a){
  return a < 0 ? -a : a;
}

void print_arr(long long *a, int n){
  for(int i = 0; i < n; i++){
    printf("%lld ", a[i]);
  }
  printf("\n");
}


long long comp(long long a, long long b){
  return mod(a) - mod(b);
}


int find_max_index(long long *a, int start, int n){
  int max_index = start;
  long long max = a[start];

  for(int i = start; i < n; i++){
    ner += 1;
    if(comp(a[i], max) > 0){
      max_index = i;

      max = a[i];
    }
  }
  return max_index;
}



void sort_vst(long long *a, int n){
  for(int i = 0; i < n; i++){
    int max_index = find_max_index(a, i, n);

    ner += 1;
    if(i == max_index)continue;
    swp += 1;
    swap(a + i, a + max_index);

  }
}


void quick_sort(long long *a, int n){
  int rel_index = (n) / 2; 
  
  long long rel = a[rel_index];

  int left  = 0;
  int right = n - 1;


  for(;left <= right;){
    printf("%d %d\n",left, right); 
    for(;comp(a[right], rel) > 0;) right--;
    for(;comp(a[left],  rel) < 0;) left++;

    if(left <= right){
      swap(a + left, a + right);
      left++;
      right--;
    }
  }

  if(left  < n - 1) quick_sort(a + left - 1,  n); 
  if(right > 0)     quick_sort(a, right + 1);
}


int main(void){
  srand(time(NULL));

  int n = 10;

  long long array0[n];
  long long array1[n];


  for(int i = 0; i < n; i++){
    int now = rand() % 100;
    int znk = rand() % 2;

    array0[i] = now - 2 * znk * now;
    array1[i] = now - 2 * znk * now;
  }

  print_arr(array0,  n);
  
  quick_sort(array0, n);
  print_arr(array0,  n);
  
  sort_vst(array1,   n);
  print_arr(array1,  n);

  printf("swaps in array 1: %lld, srav: %lld\n", swp, ner);

  return 0;
}
