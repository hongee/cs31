// Code for Project 1
// Report survey results

#include <iostream>
using namespace std;   // pp. 38-39 in Savitch 6/e explains this line

int main()
{
    int numberSurveyed;
    int numKeep;
    int numRefund;

    cout << "How many diesel Volkswagen owners were surveyed? ";
    cin >> numberSurveyed;
    cout << "How many of them say they will take a payment and keep their car? ";
    cin >> numRefund; //**
    cout << "How many of them say they will return their car for a refund? ";
    cin >> numKeep; //**

		/* The input for people willing to take payment is instead saved to the variable
		numRefunded, hence leading to a logical error in the code  */

    int pctKeep = 100.0 * numKeep / numberSurveyed; //**
    int pctRefund = 100.0 * numRefund / numberSurveyed; //**

		/* The percentage value is stored into an integer instead of a float, leading to
		incorrect/imprecise outputs */

    cout.setf(ios::fixed);   // see pp. 32-33 in Savitch 6/e
    cout.precision(1);

    cout << endl;
    cout << pctKeep << "% say they will keep their car." << endl;
    cout << pctRefund << "% say they will demand a refund." << endl;

    if (numKeep > numRefund)
        cout << "More people will keep their car than demand a refund." << endl;
    else
        cout << "More people will demand a refund than keep their car." << endl;
}
