#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "includes.h"

// information : Google
//  cplusplus.com <= dictionary
//  geeksforgeeks <= examples
//  stackoverflow <= Q&A

int main() {
  int testID = 3;

  switch (testID) {
  case 0:
    printf("Hello World!");
    break;
  case 1: // loop
    basic_loop();
    break;
  case 2: // swap
    basic_swap();
    break;
  case 3: // find max
    basic_find_max();
    break;
  case 5:
    leetcode_bubble_sort();
  default:
    printf("not a supported testID %d", testID);
    exit(-1);
  }
}

void basic_swap() {
  // basic operation of swap
  int a = 5;
  int b = 3;

  // Q: swap a and b
  int swap = a; // Step 1
  a = b;        // Step 0
  b = swap;     // Step 2
}

void basic_find_max(){
  int a[5] = {3, 1, 9, 5, 2};
  
  int aSize = 5;
  int maxnum = a[0];
  for(int i = 1;i<aSize;i++){
    if (maxnum < a[i]){
      maxnum = a[i];
    }
  }

  //Q: shift maximum value to the last position
  // {3, 1, 9, 5, 2}
  //  ^^^^ index-0 vs index-1 
  // {1, 3, 9, 5, 2}
  //     ^^^^ index-1 vs index-2 
  // {1, 3, 9, 5, 2}
  //        ^^^^ index-2 vs index-3
  // {1, 3, 5, 9, 2}
  //           ^^^^ index-3 vs index-4
  // {1, 3, 5, 2, 9}
  //              ^^ max

  for(int idx=0; idx < aSize-1; idx++)
  {
    if(a[idx]  > a[idx+1]){
      //swap
      int tmp = a[idx];
      a[idx] = a[idx +1];
      a[idx+1] = tmp;
    }
  }

  for(int i=0; i< aSize; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  
  
}


void leetcode_bubble_sort() {
  //TBV
}

void basic_loop() { // scope
  // for
  int a[5] = {3, 1, 2, 6, 5}; // static allocation
  int aSize = 5;

  for (int i = 0; i < aSize; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  // while (satisifed condition)

  int i = 0;
  // while (1) // Step 0: assume infinite loop
  while (i < aSize) // Step 3 (optional):
                    // use ~(ending condition) as "satisfied condition"
  {
    // Step 1: figure general operation and iteration
    printf("%d ", a[i]);
    i++;

    // Step 2: figure out ending condition
    // if(i == aSize){
    //   break;
    // }
  }
  printf("\n");

  // Q: print the values in a in reversed order
  /*
    a[5] = {3, 1, 2, 6, 5}
     index  0  1  2  3  4
                        ^ aSize-1
  */
  //   5, 6, 2, 1, 3

  for (int i = aSize - 1; i >= 0; i--) {
    printf("%d ", a[i]);
  }
  printf("\n");
}