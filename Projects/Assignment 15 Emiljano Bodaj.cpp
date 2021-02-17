#include <iostream>
#include <cmath>
using namespace std;

bool isOk(int q[], int c, int n) {
   for (int i = 0; i < c; ++i) // For each previous bishop, up to the current row
      if (abs(q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n)){ // if the row difference is the same as the column difference, return false.
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
int kbishops(int n, int k) {
  int* q = new int[k]; //Dynamically declare an array of size n, whatever n is (which you will declare in the int main)
  q[0] = 0; //top left corner is set to 0
  int col = 0, number = 0;  
    while (col >= 0) { //loop that goes on until interrupted 
      col++; 
      if (col == k) { //if all the bishops are found (# of which are whatever you set k to)
        number++; //everytime a set is done, add 1 to the counter (this takes the position of print in the last 8 queens problems)
        backtrack(q, col); //backtrack for more solutions
    } else {
        q[col] = q[col-1]; //start at the top rof the row of the new column
    } 
	while (col >= 0) {
      q[col]++; //descend down the row
        if (q[col] == n*n) { /// If the entire row doesn't have any conflicts, backtrack (ex. n = 5, 5*5)
          backtrack(q, col);
        } else {
          if (isOk(q, col, n) == true) { //if the okay function return true in this case, break out of the loop
            break;
          }
        
        }
        
    }
  }
  
  delete [] q; //delete the new array to avoid memory leakage
  return number; //return the number of solutions which were counted whenever all k bishops were found. 

}

int main() {
  int number_of_bishops, n_dimensions;
  while(true){
  cout << "Enter a value for n: ";
  cin >> n_dimensions;

  if(n_dimensions == -1){ //if n is -n, terminate program
    return 0; 
  }
else {
  cout << "Enter value of k: ";
      cin >> number_of_bishops;
      cout << "The number of solutions for k bishops on a n*n grid: " << kbishops(n_dimensions, number_of_bishops) << "\n";
}
  }
   return 0;
}

