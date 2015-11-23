#include <iostream>
#include <string>
using namespace std;

int main() {
  int i = 0;
  cin >> i;
  for(int j=0;j<i;j++) {
    for(int k=1;k<i-j;k++) {
      cout << " ";
    }
    for(int k=0;k<j*2 +1;k++) {
      cout << k;
    }
    cout << endl;
  }
}
