#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

const int MAX_CSTRING_LENGTH = 100;

int main () {
    char haiku[][MAX_CSTRING_LENGTH] = {
        "Do you like this test?",
        "I think it is very good",
        "I'm not good at poems"
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < strlen(haiku[i]); j++) {
            cout<<j<<endl;
            haiku[i][strlen(haiku[i]) - 1] = '\0';
        }
        cout << haiku[i] << endl;
    }
    // End result is still a better poem...
}
