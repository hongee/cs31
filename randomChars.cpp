#include <string>
#include <iostream>
using namespace std;

int main() {
  cout << "Type some characters! ";
  string s;
  getline(cin, s);

  char moooooo;

  for(int i=0;i < s.length();i++) {
    cout << s[i] << endl;
    usleep(1e5);
    cout << "\x1b[A";
  }
  return 0;
}
