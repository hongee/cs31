#include <iostream>
using namespace std;

int main() {
  int num = 0;
  cin >> num;

  for(int i=1;i<=num;i++) {
    int *arr = new int[i];

    for(int k=0;k<i;k++) {
      arr[k]=0;
    }

    for(int index=0;index<i;index++) {

      for(int j=num-i+1; j>0; j--) {

      }

    }

    for(int k=0;k<i;k++) {
      cout << arr[k];
    }

    cout << endl;
  }

}
