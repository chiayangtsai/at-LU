#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "includes.h"

// information : Google
//  cplusplus.com <= dictionary
//  geeksforgeeks <= examples
//  stackoverflow <= Q&A

int main() {
  int testID = 10;

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
  case 5: // sort
    leetcode_bubble_sort();
    break;
  case 6:
    leetcode_shuffle_lists();
    break;
  case 7:
    leetcode_sorting_sorted_arrays();
    break;
  case 8:
    basic_pointer_usage();
    break;
  case 9:
    baisc_call_by_valye_referece();
    break;
  case 10:
    basic_string_usage();
    break;
  default:
    printf("not a supported testID %d", testID);
    exit(-1);
  }
}
void basic_string_usage()
{
  //ASCII -> 8-bit -> char
  // unsigned char : [0- 255] 
  //          char : [-128, 127]

  char name[] = "John"; //{'J', 'o', 'h', 'n', '\0'}
  char tmp[8]; //{'J', 'o', 'h', 'n', '\0', X, 'Z', 'Z'}

  //loop

  //strcpy(dest address, source address)
  strcpy(tmp, name);
  printf("%s", tmp);

  //TBV : C++
  
}


int addab(int a, int b) {

  int c = a + b;

  return c;
}

void addabWithc(int x, int y, int *z) { *z = x + y; }

void addabPointers(int* x, int* y, int* z) { *z = *x + *y; }

void addabRef(int x, int y, int& z){
  z= x+y;
}

void baisc_call_by_valye_referece() {

  // Q : a+b
  int a;
  int b;
  int c;

  a = 5;
  b = 3;
  c = -1;
  c = addab(a, b); // call-by-value
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  // call-by-reference , using pointer
  a = 5;
  b = 3;
  c = -1;
  addabWithc(a, b, &c);
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  a = 6;
  b = 4;
  c = -1;
  addabPointers(&a, &b, &c);
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  // call-by-reference , using "reference"
  a= 7;
  b= 3;
  c= -1;
  addabRef(a, b, c);
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  int& q = a;
  q = 2;
  printf("a= %d, b= %d, c= %d\n", a, b, c);

//  int& k; <== error by complier

}

void basic_pointer_usage() {
  {
    // memory concept
    int a = 5; // memory address / key : &a

    // pointer declaration
    int *ptr = nullptr;
    ptr = &a;

    // reference | memory
    *ptr = 3;
    printf("a = %d\n", a);
  }

  // array : pointer
  {
    int a[5] = {4, 1, 3, 6, 2};
    //        a[0] a[1] a[2] a[3] a[4]
    // address  p   p+1  p+2  p+3  p+4
    //         a

    // memory addres of a[0]
    int *p = &(a[0]); // p is equal to a

    // memory address of a[1] : p+1
    // reference of a[1] :  *(p+1)

    for (int i = 0; i < 5; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");

    // use pointer
    for (int i = 0; i < 5; i++) {
      printf("%d ", *(a + i));
    }
    printf("\n");

    // use pointer v2
    int *ptr = a;
    for (int i = 0; i < 5; i++) {
      printf("%d ", *ptr);
      ptr++;
    }
    printf("\n");

    // use pointer v3
    ptr = a;
    for (int i = 0; i < 5; i++, ptr++) {
      printf("%d ", *ptr);
    }
    printf("\n");

    // use pointer v4 (not suggested)
    ptr = a;
    for (int i = 0; i < 5; i++) {
      printf("%d ", *ptr++);
    }
    printf("\n");
  }
}

void leetcode_shuffle_lists() {
  {
    int a[5] = {5, 3, 6, 1, 2};
    int b[5] = {1, 9, 2, 6, 7};
    int aSize = 5;
    int bSize = 5;
    int cSize = 10;
    int c[10];
    // HW1105
    // Q: given two arrayes , a and b, shuffle two arrays into array c following
    // index order
    //  c[10]= {5, 1, 3, 9, 6, 2, 1, 6, 2, 7}
    //
    //  print out the results in "c"
    //
    //  NOTE: the size of a and b are the same

    // bottom-up
    for (int i = 0; i <= 5; i++) {
      c[i * 2] = a[i];
      c[(i * 2) + 1] = b[i];
    }

    for (int i = 0; i < cSize; i++) {
      printf("%d ", c[i]);
    }
    printf("\n");

    // top-down
    int ic = 0;
    int ia = 0;
    int ib = 0;
    while (ia < aSize || ib < bSize) {
      c[ic] = a[ia];
      ic++;
      ia++;

      c[ic] = b[ib];
      ic++;
      ib++;

      // if(ia == aSize && ib == bSize){
      //   break;
      // }
    }
  }

  // HW1105 (bonus)
  {
    int a[6] = {5, 3, 6, 1, 2, 0};
    int b[4] = {1, 9, 2, 6};
    int aSize = 6;
    int bSize = 4;
    int c[10];
    // Q: given two arrayes , a and b, shuffle two arrays into array c following
    // index order
    //   c[10]= {5, 1, 3, 9, 6, 2, 1, 6, 2, 0}
    //
    //   print out the results in "c"
    //
    int ia = 0;
    int ib = 0;
    int ic = 0;

    while (ib < bSize || ia < aSize) {
      if (ia < aSize) {
        c[ic] = a[ia];
        ic++;
        ia++;
      }

      if (ib < bSize) {
        c[ic] = b[ib];
        ic++;
        ib++;
      }
      // if (ib >= bSize && ia >= aSize) {
      //   break;
      // }
    }
    for (int i = 0; i < aSize + bSize; i++) {
      printf("%d ", c[i]);
    }
    printf("\n");
  }
}

void leetcode_sorting_sorted_arrays() {
  // Q: two sorted arrays, a and b, combine a and b to c as a sorted array as
  // well.
  int a[6] = {4, 6, 7, 10, 15, 16};
  int b[8] = {0, 1, 2, 8, 12, 13, 19, 20};
  int aSize = 6;
  int bSize = 8;
  int c[14];
  // Expected c= {0, 1, 2, 4, 6, 7, 8, 10, 12, 13, 15, 16, 19, 20}
  // HW1107
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

void basic_find_max() {
  int a[5] = {3, 1, 9, 5, 2};

  int aSize = 5;
  int maxnum = a[0];
  for (int i = 1; i < aSize; i++) {
    if (maxnum < a[i]) {
      maxnum = a[i];
    }
  }

  // Q: shift maximum value to the last position
  //  {3, 1, 9, 5, 2}
  //   ^^^^ index-0 vs index-1
  //  {1, 3, 9, 5, 2}
  //      ^^^^ index-1 vs index-2
  //  {1, 3, 9, 5, 2}
  //         ^^^^ index-2 vs index-3
  //  {1, 3, 5, 9, 2}
  //            ^^^^ index-3 vs index-4
  //  {1, 3, 5, 2, 9}
  //               ^^ max

  for (int idx = 0; idx < aSize - 1; idx++) {
    if (a[idx] > a[idx + 1]) {
      // swap
      int tmp = a[idx];
      a[idx] = a[idx + 1];
      a[idx + 1] = tmp;
    }
  }

  for (int i = 0; i < aSize; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void leetcode_bubble_sort() {
  //{3, 1, 9, 5, 2}
  // ^^^^^^^^^^^^^ max
  // ^^^^^^^^^^^ 2nd max
  // ^^^^^^^ 3rd max
  //
  int a[5] = {3, 1, 9, 5, 2};
  int aSize = 5;
  for (int len = aSize; len >= 2; len--) // length
  {
    for (int idx = 0; idx < len - 1; idx++) // compare # = length -1
    {
      if (a[idx] > a[idx + 1]) {
        int tmp = a[idx];
        a[idx] = a[idx + 1];
        a[idx + 1] = tmp;
      }
    }
  }

  for (int i = 0; i < aSize; i++)
    printf("%d ", a[i]);
  printf("\n");
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