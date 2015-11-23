#include <string>
#include <iostream>
using namespace std;

int main() {
  string s;
  int i;
  getline(cin, s);
  cin >> i;
  getline(cin, s);
}

/*
  What happened?

  BS - backspace
  CR - carriage return
  LF - linefeed

  Program Does         OS Writes          OS Holds              Available to Program
    getline(cin,s);                                                 program waits
    You type X         X                  X
    You type Y         Y                  X Y
    You type BS        BS Space BS        X
    You type Z         Z                  X Z
    You type Enter     CR LF                                    X Z newline
                                                                    getline executes
                                                                    getline throws away newline and stores the rest
                                                                (empty) s gets "XZ"
    cin >> i;                                                       program waits
    You type 3         3                  3
    You type 2         2                  3 2
    You type Enter     CR LF                                    3 2 newline
                                                                    cin >> i executes
                                                                    cin throws away spaces/newlines
                                                                    cin remembers any signs
                                                                    cin consumes numbers
                                                                *3* *2* newline. (newline unconsumed)
                                                                    cin stops at the first char that is not a digit
                                                                    sets i to 32
    getline(cin,s);                                             newline (available to prog!)
                                                                    getline executes
                                                                (empty) s gets ""
    cin.ignore(10000,'\n'); - throw away characters including and up to the next newline or the next 10000 chars

*/
