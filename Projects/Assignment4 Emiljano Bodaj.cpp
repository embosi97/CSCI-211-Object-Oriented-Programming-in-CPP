#include <iostream>
#include <cmath> //for abs
using namespace std;


bool Ok(int q[], int col){// this bool is essentially the program's row and diagonal testing
    for(int i=0; i < col; i++) //checks up to, but not including, the current row
        if(q[col] == q[i] || (col-i) == abs(q[col]-q[i])){
            return false; //if there's a conflict in either one of the tests, return false
        }
    return true;//if there isn't a conflict, return true
}


void backtrack(int q[], int &col){
    col--;//goes back a column
    if(col==-1){ //if it goes out of bounds on the left side after backtracking, stop with exit(1);
        exit(0); //terminates
    }
}

void print(int q[]){ //this is the function equivalent to goto print;
	int static count = 0;
	cout << "Solution # " << count << endl;
    for(int i = 0; i < 8 ; i++){ //checks every column   
        cout << q[i]<< " ";
    }
      count++; 
      cout << endl;
}

int main(){ //int main has to do everything in a single sequence
  int q[8] = {}, col = 0; //set the array
  q[0] = 0; //far left one is set as 0 initially, like the goto version
  while(true){ // just an infinite loop made to be an infinite loop, it'll break when a condition is met or isn't
    col++; //goes to next column from the get-go
    if(col == 8) { //if columns are equal to 8, print and backtracl
      print(q);
      backtrack(q, col);
    } 
    else {
    q[col] = -1; //resets it to the top row
    }  
    while (true){ // loop
      q[col]++; // checks every row of the column
      if(q[col] == 8){ //if it goes through the entire column and every row doesn't work
        backtrack(q, col);
      }
      else {
        if (Ok(q, col) == true){ // checks every row for a conflict in the queens' positions 
          break; //goes to next row
        }
      }
    }      
    }
    return 0;
  }
