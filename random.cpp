//warm ups
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

void printSpace(int length) {
  for(int i=1;i<=length;i++) {
    cout << " ";
  }
}

void printStar(int count) {
  for(int a=1;a<=count;a++) {
    printSpace(count - a + count);
    for(int b=1;b<=a;b++) {
      cout << "🚀";
    }
    for(int c=2;c<=a;c++) {
      cout << "🚀";
    }
    cout << endl;
  }

  for(int a=count;a>=1;a--) {
    printSpace(count-a);
    for(int b=1;b<=a;b++) {
      cout << "🚀";
    }
    printSpace(2*count - 1);
    for(int b=1;b<=a;b++) {
      cout << "🚀";
    }
    cout << endl;
  }

  for(int a=count;a>=1;a--) {
    printSpace(count);
    for(int b=1;b<=a;b++) {
      cout << "🚀";
    }
    printSpace(count - a);
    printSpace(count - (a + 1));
    for(int b=1;b<=a;b++) {
      cout << "🚀";
    }
    cout << endl;
  }

}

void printHeart(int count) {
  //imagine a count * count box
  for(double a=0;a < count;a+=0.5) {

    for(double b=(count-1); b > 0;b-= 0.5) {
      if((b*b) >= a)
        cout << " 💛 ";
      else
        cout << " 💙 ";
    }

    // x = y^2
    for(double b=0;b < count;b+=0.5) {
      if((b * b) <= a)
        cout << " 💙 ";
      else
        cout << " 💛 ";
    }


    cout << endl;
  }
}

int main() {
  int count = 0;
  string option = "";
  cout << "Enter some number" << endl;
  cin >> count;
  cout << "Star or a heart? (s/h)" << endl;
  cin >> option;

  if(option == "s") {
    printStar(count);
  } else if(option == "h") {
    printHeart(count);
  } else {
    cout << "Invalid option selected" << endl;
  }

  return 0;
}
