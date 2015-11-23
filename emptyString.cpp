#include <iostream>
#include <string>
using namespace std;

//bubblesort
//once a reference is set it is bound to that specific object

void swap(char& x, char& y) {
  char t = x;
  x = y;
  y = t;
}

string bubblesort(string input) {
  for(int i = 0;i<input.size();i++) {
    //goes through every position of the string
    for(int k=i+1;k<input.size();k++) {
      if(input[k] < input[i]) {
        swap(input[k],input[i]);
      }
    }
  }
  return input;
}

string mergesort(string input) {




}


int main() {
  string input;
  getline(cin, input);

}
