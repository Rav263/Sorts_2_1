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

void print_array(long long *a, int n){
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

int partition (long long *a, int p, int r){
  long long x = *(a+r);
  int i = p - 1;
  int j;
  long long tmp;
  for (j = p; j < r; j++){
    ner += 1;
    if(comp(*(a+j), x) > 0){
      i++;

      swp += 1;
      swap(a + i, a + j);
    }
  }
  swp += 1;
  swap(a + r, a + i + 1);
  return i + 1;
}

void quicksort (long long *a, int p, int r){
  int q;
  if (p < r){
    q = partition (a, p, r);
    quicksort (a, p, q - 1);
    quicksort (a, q + 1, r);
  }
}

void quick_sort(long long *a, int n){
  quicksort(a, 0, n - 1);
}


void gen_obrt(long long *a, long long *b, int n){
  for(int i = 0; i < n; i++){
    a[i] = i + 1;
    b[i] = i + 1;
  }
}

void gen_norm(long long *a, long long *b, int n){
  for(int i = 0; i < n; i++){
    a[i] = n - i;
    b[i] = n - i;
  }
}

void gen_rand(long long *a, long long *b, int n){
  for(int i = 0; i < n; i++){
    int now = rand() ;
    int znk = rand() % 2;

    a[i] = now - 2 * znk * now;
    b[i] = now - 2 * znk * now;
  }
}


int main(void){
  srand(time(NULL));

  for(;;){
    swp = 0;
    ner = 0;
    
    printf("Please, enter type of array (or -1 to exit)\n");
    int type;
    scanf("%d", &type);
    if(type == -1)return 0;


    printf("Please, enter number of elements (or -1 to exit)\n");
    int n;
    scanf("%d", &n);
    if(n == -1)return 0;

    printf("If you want to print arrays, enter 1\n");
    int some;
    scanf("%d", &some);
    if(some == -1)return 0;


    long long *array0 = malloc(n * sizeof(long long));
    long long *array1 = malloc(n * sizeof(long long));
    
    if(type == 1)gen_norm(array0, array1, n);
    if(type == 2)gen_obrt(array0, array1, n);
    if(type == 3)gen_rand(array0, array1, n);
    if(some)print_array(array0, n);

    quick_sort(array0, n);
    if(some)print_array(array0, n);
    printf("swaps in array 0: %lld, srav: %lld\n", swp, ner);

    swp = 0;
    ner = 0;

    if(some)printf("\n");
    
    sort_vst(array1, n);
    if(some)print_array(array1, n);
    printf("swaps in array 1: %lld, srav: %lld\n", swp, ner);
  
    free(array0);
    free(array1);

    printf("\n");
  }
}
