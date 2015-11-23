#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double computeMean(int a[], int n) {
  if (n<=0)
    return 0.0;
  int total = 0;
  for (int k =0 ;k<n;k++) {
    total += a[k];
  }
  return static_cast<double>(total)/n;
}

int main() {

  const int MAX_NUMBER_OF_SCORES = 1000;
  int total = 0;
  int nscores;
  int scores[MAX_NUMBER_OF_SCORES];

  cout << "Enter the scores (negative when done):" << endl;

  for(;;) {
    int s;
    cin >> s;
    if(s < 0)
      break;
    total += s;
    scores[nscores] = s;
    nscores++;
  }
  if (nscores == 0)
    cout << "There were no scores" << endl;
  else {
    double mean = static_cast<double>(total)/nscores;
    cout << "The mean is " << mean << endl;
    double sumOfSquares = 0;
    for (int k =0; k < nscores;k++) {
      double diff = scores[k] - mean;
      sumOfSquares += diff * diff;
    }
    cout << "The std deviation is " << sqrt(sumOfSquares/nscores) << endl;
  }
}
