#include <iostream>
using namespace std;

void removeS(char* str) {
  while(*str != '\0') {
    if(*str == 'S' || *str == 's') {
      for(char* pos = str; *pos != '\0' ; pos++) {
        *pos = *(pos + 1);
      }
    } else {
      str++;
    }
  }
}


int main()
{
    char msg[50] = "She'll be a massless princess.";
    removeS(msg);
    cout << msg;  // prints   he'll be a male prince.
}
