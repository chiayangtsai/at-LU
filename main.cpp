#include "includes.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

// information : Google
//  cplusplus.com <= dictionary
//  geeksforgeeks <= examples
//  stackoverflow <= Q&A

using namespace std;

int main() {
  int testID = 9;

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
  case 8: // pointer
    basic_pointer_usage();
    break;
  case 9:
    baisc_call_by_valye_referece();
    break;

  default:
    printf("not a supported testID %d", testID);
    exit(-1);
  }
  //--- basic-level (< 7 classes)
  // pointer
  // string- C, C++
  // algorithm - sliding window
  // struct => class (light)
  // pair
  // unordered_map - look-up table (LUT), Hash Table => unordered_set
  // leetcode = two sum
  // digit representation - decimal
  // digit representation - binary

  //<--> 看題庫

  // recursive programming => dynamic programming
  // sort() (C++ standard)
  // map : key-sorted map => set
  // binary tree- Breadth-First (BF) creation

  //--- leetcode 150 studay -- finish easy-medium before "stack"

  //--- advanced-level;
  // binary tree- depth-first (DF) creation
  // binary tree - DF traversal : pre-order, in-order, post-order
  // Sort- Quick sort
  //(optional) Heap sort, merge sort
}

void basic_vector_usage() {
  // static array
  {
    int a[5] = {5, 1, 2, 4, 3};
    //        |  |  |  |  |
  }
  // dynamic array / container
  {
    vector<int> a = {5, 1, 2, 4, 3};
    for (int i = 0; i < a.size(); i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }

  // https://cplusplus.com/reference/vector/vector/?kw=vector
  // .size() : number of elements
  //     .empty() : return boolean - true : empty, false: not empty()
  // .push_back(element) : push a new element to the last position
  // .pop_back() : pop out the last element
  // .front() : the first reference
  // .back() : the last reference

  // .begin() : the first iterator
  // .end() : the last iterator

  // .erase(iterator pos) : delete the element with the iterator position
  // .insert(iterator pos, element) : insert the "element" to the "iterator pos"
  // .insert(iterator pos, source starting iterator, source ending iterator)

  printf("=== push_back() === \n");
  {
    vector<int> a;
    printf("a size = %d\n", (int)a.size());

    vector<float> f;
    f.push_back(1.2);

    int val = 10;
    a.push_back(val);
    a.push_back(0);
    printf("a size = %d\n", (int)a.size());
    for (int i = 0; i < a.size(); i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  printf("=== front(), back() ====\n");
  {
    vector<int> a = {4, 5, 1, 2};
    printf("the first element = %d\n", a.front());
    printf("the last element = %d\n", a.back());

    a.back() = 0;
    for (int i = 0; i < a.size(); i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  printf("=== iterator, begin(), end()=====\n");
  {
    vector<int> a = {3, 1, 5, 4, 2};
    //   iterator  |  |  |  |  |  |
    //             ^ begin()      ^ .end()

    printf("the first element : %d\n", *(a.begin()));
    printf("the last element : %d\n", *(a.end() - 1));
  }

  printf("===== loop ====\n");
  {
    vector<int> a = {3, 1, 5, 4, 2};
    //   iterator  |  |  |  |  |  |
    //             ^ begin()      ^ .end()

    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++) {
      printf("%d ", *it);
    }
    printf("\n");

    // auto
    int x = 5;
    auto y = x;
  }

  printf("===== loop v2====\n");
  {
    vector<int> a = {3, 1, 5, 4, 2};
    //   iterator  |  |  |  |  |  |
    //             ^ begin()      ^ .end()

    for (auto it = a.begin(); it != a.end(); it++) {
      printf("%d ", *it);
    }
    printf("\n");
  }

  printf("===== loop v3====\n"); // after 2017
  {
    vector<int> a = {3, 1, 5, 4, 2};
    //   iterator  |  |  |  |  |  |
    //             ^ begin()      ^ .end()
    for (int &x : a) {
      printf("%d ", x);
    }
    printf("\n");
  }

  printf("=== erase(), insert()======\n");
  {
    vector<int> a = {3, 1, 5, 4, 2};
    //   iterator  |  |  |  |  |  |
    //             ^ begin()      ^ .end()
    a.insert(a.begin() + 2, 0);
    for (auto &x : a)
      printf("%d ", x);
    printf("\n");

    a.erase(a.begin());
    for (auto &x : a)
      printf("%d ", x);
    printf("\n");

    a.pop_back();
    for (auto &x : a)
      printf("%d ", x);
    printf("\n");

    vector<int> b = {0, 9, 1};
    a.insert(a.end(), b.begin(), b.end());
  }
}

int getMaxAlternatingStringLength(int k, string in) {
  // TBD
  return -1;
}

void leetcode_alternating_strings() {
  // k-alternating string:
  //          StRiNg => 1-alternating string
  //          heLLow => 2-alternating string
  //          aBBaaa => NOT alternating string
  //          aaaAAbbCCCC => NOT alternating string

  // Q: Given k and a string, find the maximum sub-string length which matches
  // k-alternating string condition. Example:
  //       Given k = 2, string = "aBBaaa" => the maximum k-alternating string is
  //       BBaa, Answer:  4 Given k= 1, string = "BaBaBB" => the maximum
  //       k-alternating string is BaBaB, Anser : 5

  string in;
  int k;
  int maxLen;

  k = 1;
  in = "aBBdaaa";
  maxLen = getMaxAlternatingStringLength(k, in);
  printf("k=%d, string is %s => max len = %d (ans: 2)\n", k, in.c_str(),
         maxLen);

  k = 3;
  in = "DDaasAAbbCC";
  maxLen = getMaxAlternatingStringLength(k, in);
  printf("k=%d, string is %s => max len = %d (ans: 3)\n", k, in.c_str(),
         maxLen);

  k = 2;
  in = "aafAXbbCDCCC";
  maxLen = getMaxAlternatingStringLength(k, in);
  printf("k=%d, string is %s => max len = %d (ans: 8)\n", k, in.c_str(),
         maxLen);

  k = 3;
  in = "DDaaAAbbCC";
  maxLen = getMaxAlternatingStringLength(k, in);
  printf("k=%d, string is %s => max len = %d (ans: 0)\n", k, in.c_str(),
         maxLen);
}

void leetcode_letters_histogram() {

  // Q : print out the histogram of alphbet apperance with alphbet order.
  //
  //   NOTE: non-existence and non-alphabet shall not be printed
  //
  // Example: "a; b69ad*b%a^a;"
  //     a : 4
  //     b : 2
  //     d : 1

  //  string word = "as;lkdjfha.. al;kshjdf;laikhs;dflk jkl;j!";
  // TBD
}

void basic_string_usage() {
  // ASCII -> 8-bit -> char
  //  unsigned char : [0- 255]
  //           char : [-128, 127]

  char name[] = "John"; //{'J', 'o', 'h', 'n', '\0'}
  char tmp[8];          //{'J', 'o', 'h', 'n', '\0', X, 'Z', 'Z'}

  // loop

  // strcpy(dest address, source address)
  strcpy(tmp, name);
  printf("%s", tmp);

  // TBV : C++
}

int addab(int a, int b) {

  int x = a + b;
  return x;
}


void addabNew(int x, int y, int z) // a  b  c
{
  z = x + y;
}

void addabPointer(int x, int y, int* z) // a , b, &c
{ 
  *z = x + y; 
}

void addabPointerAlt(int* x, int* y, int* z) // &a , &b, &c
{ 
  *z = *x + *y; 
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

  a = 5;
  b = 3;
  c = -1;

  addabNew(a, b, c); // call-by-value
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  a = 5;
  b = 3;
  c = -1;

  addabPointer(a, b, &c); //call-by-reference
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  a = 5;
  b = 3;
  c = -1;

  addabPointerAlt(&a, &b, &c); //call-by-reference
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  //HW0131(VK) : start from here : "reference"
  

#if 0
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
  a = 7;
  b = 3;
  c = -1;
  addabRef(a, b, c);
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  int &q = a;
  q = 2;
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  //  int& k; <== error by complier
#endif
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

  /*
  object.method()

  pointer = object memory address (key)

  (*pointer).method()
  === equivalent
  pointer->method()


  */
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
  {
    int a[6] = {4, 6, 7, 10, 15, 16};
    int b[8] = {0, 1, 2, 8, 12, 13, 19, 20};
    int aSize = 6;
    int bSize = 8;
    int c[14];
    int cSize = aSize + bSize;
    // Expected c= {0, 1, 2, 4, 6, 7, 8, 10, 12, 13, 15, 16, 19, 20}
    // HW1107
    // HW1125 : bugfix

    int ia = 0;
    int ib = 0;
    int ic = 0;

    while (ib < bSize || ia < aSize) {
      if (ia < aSize) {
        if (a[ia] < b[ib]) {
          c[ic] = a[ia];
          ic++;
          ia++;
        }
      }

      if (ib < bSize) {
        if (a[ia] > b[ib]) {
          c[ic] = b[ib];
          ic++;
          ib++;
        }
      }
    }
    for (int i = 0; i < cSize; i++) {
      printf("%d ", c[i]);
    }
    printf("\n");
  }

  // C++ : HW1125
  {
    vector<int> a = {4, 6, 7, 10, 15, 16};
    vector<int> b = {0, 1, 2, 8, 12, 13, 19, 20};
    vector<int> c;

    int ia = 0;
    int ib = 0;
    int ic = 0;
    int aSize = a.size();
    int bSize = b.size();
    int cSize = aSize + bSize;
    c.resize(cSize);

    while (ib < bSize && ia < aSize) {
      if (ia < aSize) {
        if (a[ia] < b[ib]) {
          c[ic] = a[ia];
          ic++;
          ia++;
        }
      }

      if (ib < bSize) {
        if (a[ia] > b[ib]) {
          c[ic] = b[ib];
          ic++;
          ib++;
        }
      }
    }

    if (ia < aSize) {
      // append the rest of "a" to c
      for (int i = ia; i < aSize; i++) {
        c[ic] = a[i];
        ic++;
      }
    }

    if (ib < bSize) {
      // append therest of "b" to c
      for (int i = ib; i < bSize; i++) {
        c[ic] = b[i];
        ic++;
      }
    }
  }
  /*
          (condition)?(satisfied case):(not satisifed case)

          m;
          k = 5
          if(k==5)
          {
            m = 5
          }
          else
          {
            m = -1;
          }

          ===

          m= (k==5)?(5):(-1)

  */
  printf("== use vector methods ===\n");
  {
    vector<int> a = {4, 6, 7, 10, 15, 16};
    vector<int> b = {0, 1, 2, 8, 12, 13, 19, 20};
    vector<int> c;

    while (!a.empty() || !b.empty()) {
      // choose a or b  => x
      //  vector<int>* x= &a;
      //  if(a.empty()) x = &b;
      //  else if (b.empty()) {}
      //  else if(b.front() < a.front()) x= &b;

      // vector<int>* x = &b;
      // if(b.empty()) x = &a;
      // else if (a.empty()) {}
      // else if(a.front() < b.front()) x= &a;

      vector<int> *x = nullptr;
      if (a.empty())
        x = &b;
      else if (b.empty())
        x = &a;
      else {
        x = (a.front() < b.front()) ? (&a) : (&b);
      }

      // push x[0] to c
      // x.erase(head)
      c.push_back(x->front());
      x->erase(x->begin());
    }

    for (auto &ir : c)
      printf("%d ", ir);
    printf("\n");
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
