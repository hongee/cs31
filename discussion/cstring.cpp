#include <iostream>
#include <iomanip>
using namespace std;

void prefix(const char a[][100], char b[], int n) {
  if(n <= 0) {
    b[0] = '\0';
    return;
  }
  //for every character in the first string
  for (int i=0; a[0][i] != '\0'; ++i) {
    for (int j=1; j < n;++j) {
      if((a[j][i] == '\0') || (a[j][i] != a[0][i])) {
        //one of the strings terminated, or one of the chars is not equal
        return;
      }
      b[i] = a[0][i];
    }
  }

}

void generateMatrix(int a[][100], int n) {
  if(n<=0) return;
  int h =0, v=0, num=1;

  while(num <= n*n) {
    while(h<n && a[h][v] == 0 ) {
      a[h][v] = num;
      ++num;
      ++h;
    }
    ++v;
    --h;
    while(v<n && a[h][v] == 0 ) {
      a[h][v] = num;
      ++num;
      ++v;
    }
    --v;
    --h;
    while(h >= 0 && a[h][v] == 0) {
      a[h][v] = num;
      ++num;
      --h;
    }
    ++h;
    --v;
    while(v>=0 && a[h][v] == 0 ) {
      a[h][v] = num;
      ++num;
      --v;
    }
    ++v;
    ++h;
  }
}


void spiral(int n) {
  int a[100][100];


  for(int i=0;i<n;++i) {
    for(int k=0;k<n;++k) {
      a[i][k] = 0;
    }
  }

  generateMatrix(a, n);

  for(int i=0;i<n;++i) {
    for(int k=0;k<n;++k) {
      cout << " " << setw(5) << a[i][k] << " ";
    }
    cout << endl;
  }

}


int main() {
  char a[10000] = "fsdfsdfasdfasdf";

  spiral(10);
}
