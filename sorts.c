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


int find_max_index(long long *a, int start, int n){
  int max_index = start;
  long long max = a[start];

  for(int i = start; i < n; i++){
    ner += 1;
    if(mod(a[i]) > mod(max)){
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
  
}


int main(void){
  srand(time(NULL));

  int n = 10;

  long long array[n];

  for(int i = 0; i < n; i++){
    int now = rand() % 100;
    int znk = rand() % 2;

    array[i] = now - 2 * znk * (now);
  }

  print_arr(array, n);


  sort_vst(array, n);

  print_arr(array, n);
  printf("swaps: %lld, srav: %lld\n", swp, ner);

  return 0;
}
