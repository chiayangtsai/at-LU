#include "includes.h"
#include <algorithm>
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
  int testID = 21;

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
  case 10:
    basic_vector_usage(); // vector
    break;
  case 11:
    leetcode_pointer_increment();
    break;
  case 12:
    basic_dynamic_allocation(); // new delete
    break;
  case 14:
    leetcode_time_to_trade_stock();
    break;
  case 15:
    leetcode_time_to_trade_stock_ii(); //<=== after HW0407
    break;
  case 16:
    basic_struct_usage(); // struct
    break;
  case 17:
    basic_string_usage(); // string
    break;
  case 18:
    leetcode_alphabet_histogram(); // KES
    break;
  case 19:
    basic_time_compolexity();
    break;
  case 20:
    leetcode_time_to_trade_stock_iii();
    break;
  case 21:
    basic_pair_usage(); // pair
    break;

  default:
    printf("not a supported testID %d", testID);
    exit(-1);
  }
  //--- basic-level (1/3)
  // pair

  //--- basic-level (2/3)
  // unordered_map - look-up table (LUT), Hash Table => unordered_set
  // leetcode = two sum
  // sliding window + LUT
  // digit representation - decimal <------- focus
  // digit representation - binary <-------- focus

  //--- basic-level (3/3)
  // recursive programming => dynamic programming
  // sort() (C++ standard)
  // map : key-sorted map => set
  // binary tree- Breadth-First (BF) creation

  //----- leetcode 150 study plan ---------//
  // easy -> medium
  // before "stack"

  //----- advanced-level ------------//
  // data structure & advanced algorithm
}

void basic_pair_usage() {
  /*
     John
     90
  */
  vector<string> names = {"John", "Mary", "Jay"};
  vector<int> scores = {95, 70, 98};

  struct SNameData {
    string name;
    int score;
  };

  // vector<SNameData> sData;
  /*
    std::make_pair(type1, type2) <=== HW0411(VK) start from here.
  
  */

  vector<pair<string, int>> sData;
  for(int i=0; i< names.size(); i++){
    string name = names[i];
    int score = scores[i];

    pair<string, int> tmpObj;
    tmpObj.first = name;
    tmpObj.second = score;    
    sData.push_back(tmpObj);
    
  }

  
  
}

void basic_time_compolexity() {
  /*
        #     time
  A    10      1     <== O(N^2)
       20      4
       30      9
       40     16

  B    10      2   <== O(N)
       20      4
       30      6
       40      8


  If a horizontal line : O(1)

  */
}

void leetcode_alphabet_histogram() {
  string ss = "    &%h#aa( z 90A ch";
  /*
  Q: find the histogram of the lower-case alphabet and print out in the
  following format (following a->z order)

  a 2
  c 1
  h 2
  z 1

  time complexity  : O(N)
  space complexity : O(1)

  */
  // HW0407

  vector<int> tab(26, 0); // look-up table :     alphabet <-> show times
  //                                            alphabet <-> ascii index <->
  //                                            show times
  //                                                         ^^^^^^^^^^^^^
  //                                                         ^^^^^^^^^^^
  //                                                          key value  <==
  //                                                          pair
  //  KES algorithm

  // Step 1: collect statistics   : O(N)
  int i = 0;
  while (i != ss.size()) {
    if (ss[i] >= 'a' && ss[i] <= 'z') {
      int index = ss[i] - 'a';
      tab[index]++;
    }
    i++;
  }

  // Step 2: analyze the statistics | raw data with statistics

  for (char c = 'a'; c <= 'z'; c++) // O(1)
  {

    if (tab[c - 'a'] > 0) {
      printf("%c  %d\n", c, tab[c - 'a']);
    }
  }

#if 0  
  string output; // "haazch"
  int i = 0;

  while (i != ss.size()) {
    if ((ss[i] >= 'a' && ss[i] <= 'z') {
      output.push_back(ss[i]);
    }
    i++;
  }

  for (auto &x : output) {
    printf("%c", x);
  }
#endif
}

void basic_struct_usage() {
  /*

     2-> 3->


  */

  cout << "------- v0--------" << endl;
  {
    struct SNODE {
      int val;
      SNODE *link;
      bool isEnd;
    };

    SNODE oneNode;
    oneNode.val = 2;
    oneNode.isEnd = false;

    SNODE secondNode;
    secondNode.val = 3;
    secondNode.isEnd = true;
    oneNode.link = &secondNode;

    // Q: Given a head node link, print out all elements in this data chain
    // (Linked list)
    SNODE *headPtr = &oneNode;
    //  2->3->5->3->

    while (true) {

      printf("%d->", headPtr->val); // 1st node: 2->

      // exception
      if (headPtr->isEnd)
        break;

      // general
      headPtr = headPtr->link;
      /*
      if(!(*headPtr).isEnd){
        headPtr = (*headPtr).link; //headptr => 2nd node
      }
      else{
        be
      }
      */
    }
    printf("\n");
  }

  cout << "------- v1: use nullptr--------" << endl;
  {
    struct SNODE {
      int val;
      SNODE *link;
    };

    SNODE oneNode;
    oneNode.val = 2;
    oneNode.link = nullptr;

    SNODE secondNode;
    secondNode.val = 3;
    secondNode.link = nullptr;

    oneNode.link = &secondNode;

    // Q: Given a head node link, print out all elements in this data chain
    // (Linked list)
    SNODE *headPtr = &oneNode;
    //  2->3->

    while (true) {

      printf("%d->", headPtr->val); // 1st node: 2->

      // exception
      if (headPtr->link == nullptr)
        break;

      // general
      headPtr = headPtr->link;
    }
    printf("\n");
  }

  cout << "------- v2: use constructor to initiate--------" << endl;
  {
    // int* p = int(5);
    // delete p;

    struct SNODE {
      int val;
      SNODE *link;

      //-- constructor --//
      SNODE() {
        val = -1;
        link = nullptr;
      }

      SNODE(int v) {
        val = v;
        link = nullptr;
      }
      // overloading
      SNODE(int v, SNODE *l) {
        val = v;
        link = l;
      }
    };

    SNODE secondNode(3);
    SNODE oneNode(2, &secondNode);

    // SNODE* pNode = new SNODE(5, nullptr);

    // Q: Given a head node link, print out all elements in this data chain
    // (Linked list)
    SNODE *headPtr = &oneNode;
    //  2->3->

    while (true) {

      printf("%d->", headPtr->val); // 1st node: 2->

      // exception
      if (headPtr->link == nullptr)
        break;

      // general
      headPtr = headPtr->link;
    }
    printf("\n");
  }
  cout << "------- v3: destructor--------" << endl;
  {
    struct SNODE {
      int val;
      SNODE *link;

      //-- constructor --//
      SNODE() {
        val = -1;
        link = nullptr;
      }

      SNODE(int v) {
        val = v;
        link = nullptr;
      }
      // overloading
      SNODE(int v, SNODE *l) {
        val = v;
        link = l;
      }

      //--- destructor --//
      ~SNODE() {
        if (link != nullptr) {
          delete link;
        }
      }
    };

    // Q: create a linked list; given k, create a list like the follows:
    //  0->1->2->3......->k
    int k = 6;

    SNODE *head = new SNODE(0); // 0->
    SNODE *ptr = head->link;

    for (int i = 1; i <= k; i++) {
      ptr = new SNODE(i); // 0->1->2-> ...->k->
      ptr = ptr->link;
    }

    // 0-> 1-> 2.....-> k->
    // ^^^ ^^^ ^^^^     ^^^^
    //     k+1 nodes
    delete head;

    //--- use vector
    vector<SNODE> vNodes(k);
    for (int i = 0; i <= k; i++) {
      vNodes[i].val = i;

      if (i < k)
        vNodes[i].link = &(vNodes[i + 1]);
    }
  }
}

int maxProfit_iii(vector<int> &prices) {
  // HW0411
  // time complexity requirement : at least O(N^2), best O(N)
  return -1;
}

void leetcode_time_to_trade_stock_iii() {
  // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

  /*
    You are given an array prices where prices[i] is the price of a given stock
  on the ith day.

  Find the maximum profit you can achieve. You may complete at most two
  transactions.

  Note: You may not engage in multiple transactions simultaneously (i.e., you
  must sell the stock before you buy again).



  Example 1:

  Input: prices = [3,3,5,0,0,3,1,4]
  Output: 6
  Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
  3-0 = 3. Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit =
  4-1 = 3. Example 2:

  Input: prices = [1,2,3,4,5]
  Output: 4
  Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
  5-1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later,
  as you are engaging multiple transactions at the same time. You must sell
  before buying again. Example 3:

  Input: prices = [7,6,4,3,1]
  Output: 0
  Explanation: In this case, no transaction is done, i.e. max profit = 0.


  Constraints:

  1 <= prices.length <= 105
  0 <= prices[i] <= 105

  */
  vector<int> prices;

  prices = {1, 3, 5, 4, 3, 7, 6, 9, 2, 4};
  printf("max profit : %d (ans 10)\n\n", maxProfit_iii(prices));

  prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
  printf("max profit : %d (ans 13)\n\n", maxProfit_iii(prices));

  prices = {3, 3, 5, 0, 0, 3, 1, 4};
  printf("max profit : %d (ans 6)\n\n", maxProfit_iii(prices));

  prices = {1, 2, 3, 4, 5};
  printf("max profit : %d (ans 4)\n\n", maxProfit_iii(prices));

  prices = {7, 6, 4, 3, 1};
  printf("max profit : %d (ans 0)\n\n", maxProfit_iii(prices));
}

/*
       0  1  2  3  4  5  6  7  8 <== day
       7, 2, 6, 9, 5, 1, 3, 6, 4 <== price
          h (賣)
       t
profit 0     4  7  3     2  5  3
maxP   0     4  7  7     7  7  7 <==

*/

int maxProfitAlt(vector<int> &prices) {
  int maxP = 0;
  int t = 0;
  int profit = 0;

  for (int h = 1; h < prices.size(); h++) {
    if (prices[h] > prices[t]) {
      profit = prices[h] - prices[t];
      if (profit > maxP) {
        maxP = profit;
      }
    } else // move tail index
    {
      t = h;
    }
  }

  return maxP;
}

/*
       0  1  2  3  4  5  6  7  8 <== day
       7, 2, 6, 9, 5, 1, 3, 6, 4 <== price
       h(買)
                t
profit 2  7  3     1  5  3     0
maxP   7  7  5     5  5  3     0
       ^^
*/

int maxProfitRL(vector<int> &prices) {
  int maxP = 0;
  int t = prices.size() - 1;
  int profit = 0;
  // HW0328
  // HW0407

  for (int h = prices.size() - 2; h > 0; h--) {
    if (prices[h] < prices[t]) {

      profit = prices[t] - prices[h];

      if (profit > maxP) {
        maxP = profit;
      }
    } else {
      t = h;
    }
  }

  return maxP;
}

int maxProfit(vector<int> &prices) {
  // HW0314 HW0521 : sliding window algorithm
  int currentbuyprice = 0;
  int Currentincome = 0;
  int Hicome = 0;

  for (int i = 0; i < prices.size(); i++) {
    if (i == 0 || prices[i] <= currentbuyprice) {
      currentbuyprice = prices[i];
    } else {
      Currentincome = prices[i] - currentbuyprice;
      if (Currentincome >= Hicome) {
        Hicome = Currentincome;
      }
    }
  }

  return Hicome;
}

void leetcode_time_to_trade_stock_ii() {

  vector<int> prices;

  printf("-----v2: R->L ------ \n");
  prices = {7, 1, 5, 3, 6, 4};
  printf("max profit : %d (ans 5)\n", maxProfitRL(prices));
  prices = {7, 6, 4, 3, 1};
  printf("max profit : %d (ans 0)\n", maxProfitRL(prices));
  prices = {7, 2, 6, 9, 5, 1, 3, 6, 4};
  printf("max profit : %d (ans 7)\n", maxProfitRL(prices));
}

void leetcode_time_to_trade_stock() {
  // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description

  /*

You are given an array prices where prices[i] is the price of a given stock on
the ith day.

You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because
you must buy before you sell. Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4

   */

  vector<int> prices;

  printf("-----v0 ------ \n");
  prices = {7, 1, 5, 3, 6, 4};
  printf("max profit : %d (ans 5)\n", maxProfit(prices));

  prices = {7, 6, 4, 3, 1};
  printf("max profit : %d (ans 0)\n", maxProfit(prices));

  prices = {7, 2, 6, 9, 5, 1, 3, 6, 4};
  printf("max profit : %d (ans 7)\n", maxProfit(prices));

  printf("-----v1 ------ \n");
  prices = {7, 1, 5, 3, 6, 4};
  printf("max profit : %d (ans 5)\n", maxProfitAlt(prices));

  prices = {7, 6, 4, 3, 1};
  printf("max profit : %d (ans 0)\n", maxProfitAlt(prices));

  prices = {7, 2, 6, 9, 5, 1, 3, 6, 4};
  printf("max profit : %d (ans 7)\n", maxProfitAlt(prices));

  printf("-----v2: R->L ------ \n");
  prices = {7, 1, 5, 3, 6, 4};
  printf("max profit : %d (ans 5)\n", maxProfitRL(prices));

  prices = {7, 6, 4, 3, 1};
  printf("max profit : %d (ans 0)\n", maxProfitRL(prices));

  prices = {7, 2, 6, 9, 5, 1, 3, 6, 4};
  printf("max profit : %d (ans 7)\n", maxProfitRL(prices));
}

void basic_dynamic_allocation() {

  /*
    array : pointer with "stack" allocated memory
  */
  int a[5]; //<== stack
  int *p;   //<== pointer without any allocated memory
  p = &(a[1]);

  /*
  pointer with a allocated memory : dynamic memory allocation

  */
  // C++ : array
  p = new int[6]; // must be released before the memory scope ends
  int *m = p;
  m++;
  delete[] p;

  // C++ : single object : int, char, float ....
  p = new int;
  // Q: assign -1 to the memory of p pointing to
  *p = -1; // p is a pointer, *p is the reference / memory
  printf("P=%d\n", *p);
  delete p;

  cout << "----- constructor --------" << endl;
  p = new int(5);
  printf("--- %d --\n", *p);
  delete p;

  vector<int> x; // object
  x.push_back(0);
  x.push_back(1);

  // x = {0, 1}
  vector<int> *xp = &x;
  // Q: use xp to push_back a new element -1
  //  x => {0, 1, -1}

  (*xp).push_back(-1);

  xp->push_back(-1);

  for (auto it = x.begin(); it != x.end(); it++) {
    printf("%d\n", *it);
  }

  cout << "-------- C : malloc, free " << endl;
  //  malloc(), free()

  /*
  1 byte = 8 bits

  1 "char" = 1 byte = 8 bits  <====
     => 2^8 => 256 => -2^7 .... 0 ..... 2^7-1 => -128.. 0.... 127
                                                        ^^^^^^^^^
                                                         ASCII
  1 "unsigned char" = 1 byte = 8 bits
    => 0... 2^8-1 => 0... 255

  1 "short" = 2 bytes = 16 bits
  1 "int" = 4 bytes = 32 bits <===


  */
  unsigned char num = 255;
  num = num + 1;
  printf("num = %d", (int)num);

  // Q: allocate 6 integer to a pointer ptr
  int *ptr = new int[6];
  delete[] ptr;
  // empty pointer
  ptr = nullptr; // C++

  ptr = (int *)malloc(6 * sizeof(int));
  free(ptr);
  ptr = NULL; // C
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
  // .empty() : return boolean - true : empty, false: not empty()
  // .push_back(element) : push a new element to the last position
  // .pop_back() : pop out the last element
  //
  // .front() : the first reference
  // .back() : the last reference

  // .begin() : the first iterator
  // .end() : the last iterator

  // .erase(iterator pos) : delete the element with the iterator position
  // .insert(iterator pos, element) : insert the "element" to the "iterator pos"
  // .insert(iterator pos, source starting iterator, source ending iterator)

  // reverse(start iterator, end iterator)

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
  printf("%s\n", tmp);

  cout << "---- c++ -------" << endl;
  // vector<char> a = {'J', 'o', 'h', 'n'}
  string a = "John";

  /*
     .size() :   length of the string
      => .length()

      .push_)back() : append new char to the end of string
      .begin(), .end()


      .c_str() : convert c++ string to c style string

      std::to_string(<data type>) : convert to string
      std::stoi(string) : convert string to integer

      std::reverse(start iterator, end iterator)

      .substr(start position, length)
         ==>  .substr(start position)  to the last one

  */

  a.push_back('y');
  printf("%s\n", a.c_str());

  // Q: print out every charactor in a
  //  J
  //  o
  //  h
  //  n
  //  y

  for (auto it = a.begin(); it != a.end(); it++) {
    printf("%c\n", *it);
  }

  for (auto &x : a) {
    printf("%c\n", x);
  }

  string tmp1 = "7685";

  int tmpint = stoi(tmp1);

  cout << tmpint << endl;

  // Q: revert the digits order of an integer
  int num = 89762;
  // => num = 26798
  string numstring = to_string(num);
  string newnumstring;
  for (auto it = numstring.end() - 1; it >= numstring.begin(); it--) {
    newnumstring.push_back(*it);
  }
  num = stoi(newnumstring);
  cout << num << endl;

  cout << "---- std::reverse()------" << endl;

  reverse(numstring.begin(), numstring.end());
  cout << numstring << endl;

  cout << "---- .substr() -----" << endl;
  string name2 = "Johny";
  //               ^^^
  string substr = name2.substr(1, 3);
  cout << substr << endl;

  cout << name2.substr(2) << endl;
}

int addab(int a, int b) {

  int x = a + b;
  return x;
}

void addabNew(int x, int y, int z) // a  b  c
{
  z = x + y;
}

void addabPointer(int x, int y, int *z) // a , b, &c
{
  *z = x + y;
}

void addabPointerAlt(int *x, int *y, int *z) // &a , &b, &c
{
  *z = *x + *y;
}

void addabReference(int a, int b, int &c) { c = a + b; }

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

  addabPointer(a, b, &c); // call-by-reference
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  a = 5;
  b = 3;
  c = -1;

  addabPointerAlt(&a, &b, &c); // call-by-reference
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  a = 5;
  b = 3;
  c = -1;
  addabReference(a, b, c);
  printf("a= %d, b= %d, c= %d\n", a, b, c);

  int x = 5;
  int &y = x; // "reference" type must be initialized
  y = -1;
  printf("x= %d\n", x);

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
  {
    int a[5] = {4, 1, 3, 6, 2};
    //        a[0] a[1] a[2] a[3] a[4]

    // Q: integer pointer "p" to the first element address in a
    // int* p = &(a[0]);
    int *p = a;

    // Q: integer pointer "q" to the index-1 element address in a
    int *q = a + 1; // *(a+1) <==> a[1]
    //                 a+1    <==> &(a[1])

    printf("q[0]= %d\n", q[0]);   // 1
    printf("q[3]= %d\n", q[3]);   // 2
    printf("q[4]= %d\n", q[4]);   // UNKNOWN // memory violation
    printf("q[-1]= %d\n", q[-1]); // 4
  }
  return;

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

void leetcode_pointer_increment() {

  // Q: Given an array, sum up all numbers and print out the sum
  int nums[5] = {3, 1, 5, 4, 2};
  int nSize = 5;

  int *p = nums;
  int sum = 0;
  for (int i = 0; i < nSize; ++i) {
    sum += *p++;
  }
  printf("sum = %d\n", sum);

  //  *(&(nums[2])+1)  => 4
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
