#include <iostream>
#include <cmath>
using namespace std;

bool isOk(int q[], int c) {
  for (int i = 0; i < c; i++) {
    if (q[i] == q[c] || c - i == abs(q[c] - q[i]))
      return false;
  }
      return true;  
}

void backtrack(int q[], int &c) {
  c--;
  if (c == -1) {
return;
//  q[c]++;  
  }
  
}
int nqueens(int n) {
  int* q = new int[n]; //Dynamically declare an array of size n, whatever n is
  q[0] = 0; //top left corner is set to 0
  int col = 0, number = 0; //counter  
    while (col >= 0) {
      col++;
      if (col == n ) {
        number++; //everytime a set is done, add 1 to the counter
        backtrack(q, col); //backtrack for more solutions
    } else {
        q[col] = -1; //start at the top rof the row of the new column
    } while (col >= 0) {
      q[col]++; //descend down the row
        if (q[col] == n) { //if it doesn't find any solutions in that current row, backtrack
          backtrack(q, col);
        } else {
          if (isOk(q, col) == true) {
            break;
          }
        
        }
        
    }
  }
  
  delete [] q; //delete the new array to avoid memory leakage
  return number; //return the number of solutions

}

int main() {
  int n;
  cout << "Enter a value for N: ";
  cin >> n;
  if(n > 0 && n <= 15){
  for (int i = 1; i <= n; ++i) {
    cout << "N Queen at " << i << " has " << nqueens(i) << " solutions ";
    cout << endl;
  }
  }
    return 0;
}
