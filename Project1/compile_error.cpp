// Code for Project 1
// Report survey results

#include <iostream>
using namespace std;   // pp. 38-39 in Savitch 6/e explains this line

int main()
{
    int numberSurveyed, numKeep; //**
    int numKeep;
    int numRefund;
		//numKeep is accidentally redefined
		/*
		compile_error.cpp: In function 'int main()':
		compile_error.cpp:10:9: error: redeclaration of 'int numKeep'
		compile_error.cpp:9:25: note: 'int numKeep' previously declared here
		*/

    cout >> "How many diesel Volkswagen owners were surveyed? ";//**
		//the cout operator's direction is reversed
		/*
		the standard library throws a whole bunch of errors
		*/
    cin >> numberSurveyed;
    cout << "How many of them say they will take a payment and keep their car? ";
    cin >> numKeep;
    cout << "How many of them say they will return their car for a refund? ";
    cin >> numRefund;

    double pctKeep = 100.0 * numKeep / numberSurveyed;
    double pctRefund = 100.0 * numRefund / numberSurveyed;

    cout.setf(ios::fixed);   // see pp. 32-33 in Savitch 6/e
    cout.precision(1);

    cout << endl;
    cout << pctKeep << "% say they will keep their car." << endl;
    cout << pctRefund << "% say they will demand a refund." << endl;

    if (numKeep > numRefund;) //**
        cout << "More people will keep their car than demand a refund." << endl;
    else
        cout << "More people will demand a refund than keep their car." << endl;
		//an unnecessary semicolon is added to the conditional expression
		/* Leads to
		compile_error.cpp: In function 'int main()':
		compile_error.cpp:30:29: error: expected ')' before ';' token
		compile_error.cpp:30:30: error: expected primary-expression before ')' token
		compile_error.cpp:32:6: error: 'else' without a previous 'if'
		*/


}
