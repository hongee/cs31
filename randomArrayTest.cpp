#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

bool contains_reverse(char first [], char second []) {
  for(int i=0;first[i] != '\0';++i) {
    for(int k=strlen(second)-1;k>=0;--k) {
      cout << second[k] << endl;
      cout << first[i] << endl;
      int pos = i;
      if(second[k] == first[i] && k == 0) {
        return true;
      } else if(second[k] != first[i]) {
        cout << "broke" << endl;
        break;
      } else {
        ++pos;
      }
    }
  }
  return false;
}

int main() {
  cout << contains_reverse("This is a test", "set");
  cout << contains_reverse("This is a test", "tes");
  cout << contains_reverse("This is a test", "i sih");
  cout << contains_reverse("This is a test", "isih");
}
