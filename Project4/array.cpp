#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void swapString(string& a, string& b);
int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);

//utility function to print the array
void printArray(string a[],int n) {
  for(int i=0;i<n;i++) {
    cerr << a[i] << ", ";
  }
  cerr << endl;
}

int main() {
  string s[6] = { "ben", "donald", "ted", "marco", "hillary", "ted"};
  string g[8] = { "ben", "donald", "ted", "marco", "hillary", "ted","ted","ted"};
  string n[6] = { "ben", "ben", "ben", "ben"};
  string d[9] = {
      "ben", "chris", "marco", "marco", "donald", "donald", "donald", "marco", "marco"
  };
  string folks[6] = { "chris", "marco", "", "ben", "donald", "john" };
  string group[5] = { "chris", "marco", "john", "", "carly" };
  string names[10] = { "ted", "hillary", "rand", "bernie", "mike", "jeb" };
  string names1[10] = { "hillary", "rand", "bernie" };
  string names2[10] = { "ted", "bernie" };
  string names3[10] = { "bernie", "mike", "jeb" };
  string set1[10] = { "carly", "mike", "bernie", "hillary" };
  string set2[10] = { "ben", "donald" };
  string cand[6] = { "bernie", "hillary", "donald", "marco", "carly", "ben" };
  string cand2[4] = { "donald", "hillary", "jeb", "ben" };
  string cand3[4] = { "yyy", "zzz", "donald", "ben" };
  string cand4[6] = { "yyy", "zzz", "donald", "ben", "donald", "donald" };


  assert(lookup(s,5,"ben") == 0);
  assert(lookup(s,5,"clinton") == -1);
  assert(lookup(s,5,"marco") == 3);
  assert(lookup(s,5,"BEN") == -1);

  assert(positionOfMax(s, 5) == 2);
  assert(positionOfMax(s, 2) == 1);
  assert(positionOfMax(s, 6) == 2);
  assert(positionOfMax(n, 4) == 0);

  assert(countRuns(n, 4) == 1);
  assert(countRuns(g, 8) == 6);
  assert(countRuns(d, 9) == 5);

  assert(differ(s, 6, g, 8) == 6);
  assert(differ(s, 6, n, 4) == 1);
  assert(differ(s, 4, s, 4) == 4);
  assert(differ(folks, 6, group, 5) == 2);
  assert(differ(folks, 2, group, 1) == 1);

  assert(subsequence(g, 8, s, 6) == 0);
  assert(subsequence(g, 8, s, 6) == 0);
  assert(subsequence(names, 5, names2, 2)==-1);
  assert(subsequence(names, 6, names1, 3)==1);
  assert(subsequence(names, 6, names3, 3)==3);
  assert(subsequence(names, 6, names, 6)==0);
  assert(subsequence(names, 6, names2, 0)==0);

  assert(lookupAny(names, 10, names1, 3) == 1);
  assert(lookupAny(s, 6, names2, 2) == 2);
  assert(lookupAny(group, 5, names1, 3) == -1);
  assert(lookupAny(names, 6, set1, 4) == 1);
  assert(lookupAny(names, 6, set2, 2) == -1);

  //these mutate s
  assert(appendToAll(s, 5, "!!!!!") == 5 && s[0] == "ben!!!!!");
  assert(appendToAll(s, 1, "!!!!!") == 1 && s[1] == "donald!!!!!" && s[0] == "ben!!!!!!!!!!");
  assert(appendToAll(s, -1, "!!!!!") == -1);

  assert(flip(d, 3) == 3 && d[2] == "ben" && d[0] == "marco" && d[1] == "chris");
  assert(flip(d, 4) == 4 && d[0] == "marco" && d[1] == "ben" && d[2] == "chris");

  assert(rotateLeft(g, 6, 0) == 0 && g[5] == "ben" && g[0] == "donald");
  assert(rotateLeft(g, 6, 2) == 2 && g[5] == "marco" && g[0] == "donald");

  //actual results examined from cerr
  assert(split(cand, 6, "chris") == 3);
  assert(split(cand2, 4, "donald") == 1);
  assert(split(cand2, 4, "a") == 0);
  assert(split(cand2, 4, "zzzzzzzzzzz") == 4);
  assert(split(cand3, 4, "donald") == 1);
  assert(split(cand4, 6, "donald") == 1);


  cerr << "All tests succeeded!" << endl;
}

//function to swap strings
void swapString(string& a, string& b) {
  string temp = b;
  b = a;
  a = temp;
}

//for each item in array a append value
int appendToAll(string a[], int n, string value) {

  if(n < 0) {
    return -1;
  }
  for(int i = 0; i<n; ++i) {
    a[i] += value;
  }
  return n;
}

//for each item in array a check if value == target
int lookup(const string a[], int n, string target) {
  if(n < 0) {
    return -1;
  }
  for(int i = 0; i<n ; ++i) {
    if(a[i] == target) {
      return i;
    }
  }
  return -1;
}

//go through array, if item visited is larger than all previous items, set that
//as new maximum
int positionOfMax(const string a[], int n) {
  if(n < 0 || n == 0) {
    return -1;
  }

  string currentMax = "";
  int maxPos;

  for(int i = 0; i<n ; ++i) {
    if(a[i] > currentMax) {
      maxPos = i;
      currentMax = a[i];
    }
  }
  return maxPos;
}

//bubble the item at pos to the right of the array
int rotateLeft(string a[], int n, int pos) {
  if(pos >= n || n < 0) {
    //pos cant be longer than size of array
    //n cant be
    return -1;
  }
  for(int i=pos; i<n-1; ++i) {
    swapString(a[i], a[i+1]);
  }
  return pos;
}

/*
Return the number of sequences of one or more consecutive identical items
in a.
*/
int countRuns(const string a[], int n) {
  if(n < 0) {
    return -1;
  }

  string testStr = "";
  int count = 0;
  for(int i=0;i<n;++i) {
    //the current similar sequence has changed!
    //increment counter, set our current sequence to new string
    if(testStr != a[i]) {
      testStr = a[i];
      ++count;
    }
  }
  return count;
}

/*
Reverse the order of the elements of the array and return n.
*/
int flip(string a[], int n) {
  if(n < 0) {
    return -1;
  }
  //swap 0 and n, 1 and n-1...
  for(int i=0; i<n/2; ++i) {
    swapString(a[i], a[n-1-i]);
  }
  return n;
}

/*
Return the position of the first corresponding elements of a1 and a2 that
are not equal. n1 is the number of interesting elements in a1, and n2 is
the number of interesting elements in a2. If the arrays are equal up to
the point where one or both runs out, return the smaller of n1 and n2.
*/
int differ(const string a1[], int n1, const string a2[], int n2) {
  if(n1 < 0 || n2 < 0) {
    return -1;
  }

  for(int i=0;i<n1;++i) {
    if(i>=n2) {
      //string 1 is larger than string 2, return string 2 value
      return n2;
    }
    if(a1[i] != a2[i]) {
      return i;
    }
  }
  //finish running through n1 without returning. n1 either smaller or equals n2
  return n1;
}

//attempt to find subsequence!
int subsequence(const string a1[], int n1, const string a2[], int n2) {
  if(n2 > n1 || n1 < 0 || n2 < 0) {
    //string 2 is longer than n1, not possible
    return -1;
  }

  //for every item in a1...
  for(int i=0;i<n1;++i) {
    int k;
    //try to match itself and every next item on the sequence with sequence a2
    for(k=0;k<n2;++k) {
      if((k+i >= n1) || (a1[k+i] != a2[k])) {
        break;
      }
    }
    if(k==n2) {
      //loop has gone through entire subseq and it has all matched in a1 (ie did not break)
      return i;
    }
  }

  return -1;
}

//check if any items in array 2 exist in array 1
int lookupAny(const string a1[], int n1, const string a2[], int n2) {

  if(n1 < 0 || n2 < 0) {
    //string 2 is longer than n1, not possible
    return -1;
  }

  //for every item in array 1
  for(int i=0;i<n1;++i) {
    //try to find a match in array 2
    for(int k=0;k<n2;++k) {
      //if that match exists, return the pos in a1
      if(a1[i] == a2[k]) {
        return i;
      }
    }
  }
  return -1;
}

//go through element of array
//if the item is greater or equal to splitter
//shift that item all the way to the right
//()
int split(string a[], int n, string splitter) {

  if(n < 0) {
    return -1;
  }
  int i = 0;
  int k = n;
  printArray(a, n);
  for(i=0;i<k;i++) {
    if(a[i] > splitter) {
      //is greater than the divider, switch with the right most
      //stay in the same pos, ignore the right most item (since its in the right place)
      cerr << a[i] << " <-swapping this " << endl;
      swapString(a[i], a[k-1]);
      --i;
      --k;
    } else if (a[i] == splitter) {
      //is the same as the splitter
      //is what im swapping with the same as myself? (ie a duplicate)
      if(a[k-1] == a[i]) {
        //swap with the next non duplicate
        int currentLast = k-1;
        while(a[currentLast] == a[i] && currentLast != i) {
          currentLast--;
        }
        if(currentLast == i) {
          //attempting to swap with myself.
          //array is properly sorted.
          break;
        }
        swapString(a[currentLast], a[i]);
      } else {
        swapString(a[i], a[k-1]);
      }
      //stay in the same place
      --i;
    }
    printArray(a, n);
  }
  cerr << "Done" << endl << endl;
  return i;
}
