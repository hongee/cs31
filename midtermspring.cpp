#include <iostream>
#include <string>
using namespace std;

int main() {
  for(int i = 5; i > 0; i--) {
    for(int m = 5; m > 0; m--) {
      if(m <= i) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}
