#include <iostream>
#include <cmath>
using namespace std;


bool Ok(int q[], int col){// this bool is essentially the program's row and diagonal testing
    for(int i=0; i < col; i++) //checks up to the current row
        if(q[col] == q[i] || (col-i) == abs(q[col]-q[i])){
            return false; //if there's a conflict, return false
        }
    return true;//if there isn't a conflict, return true
}


void backtrack(int q[], int &col){
    col--;//goes back a column
    if(col==-1){ //if it goes out of bounds on the left side after backtracking, stop with exit(1);
        exit(1);
    }
}

void print(int q[]){ //this is the function equivalent to goto print;
    for(int i = 0; i < 8 ; i++){ //checks every column   
        cout << q[i] << " ";
    }
      cout << endl;
}

int main(){
  int q[8] = {}, col = 0, count; //set the array
  q[0] = 0; //far left one is set as 0 initially, like the goto version
  while(col >= 0){ // while col is greater than or less to 0
    col++;
    if(col == 8) { //if columns are equal to 8, print and backtracl
      print(q);
      backtrack(q, col);
    } 
    else {
    q[col] = -1; //reset it 
    }  
    while (col >= 0){ // loop
      q[col]++; // checks every row of the column
      if(q[col] == 8){
        backtrack(q, col);
      }
      else {
        if (Ok(q, col)){ // checks every row a for conflict all
          break;
        }
      }
    }      
    }
    return 0;
  }
