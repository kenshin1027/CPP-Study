#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int a[100001];
int fama[101];


void updateWeight(int value) {
  int b[100001] = {0};
  a[value] = 1;
  for (int i = 1; i < 100000; i++) {
    if (b[i] == 1) continue;
    if (a[i] == 1) {
        if(a[i + value] == 0 && i != value) {
          a[i + value] = 1;
          b[i + value] = 1;
        }
        if(a[abs(i - value)] == 0 ) {
          a[abs(i - value)] = 1;
          b[abs(i - value)] = 1;
        }
    }
  }
}
int main() {
    int N;
    cin >> N;
    for(int i=0;i < N; i++) {
      cin >> fama[i];
      updateWeight(fama[i]);
    }
    int counter = 0;
    for(int i = 1; i <= 100000; i++) {
      if(a[i] == 1) counter++;      
    }
    cout << counter;
    return 0;
}
