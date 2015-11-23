#include <iostream>
#include <string>
using namespace std;

int main() {
  // 2 ways to write out doubles - scientific notation (esomething), fixed notation
  // by default it truncates all extra 0s (so 1.0000 becomes 1)
  // output does not however change the value of the actual double

  cout.setf(ios::scientific);
  cout.precision(5);

  cout << 1.34234 * 1.2412 << endl;

  return 0;
}
