#include <iostream>
#include <cmath> //for abs
using namespace std;

bool Ok(int q[], int col) {
  static int mp[3][3] = { //man preference
    {0,2,1}, 
    {0,2,1}, 
    {1,2,0}
  };
  static int wp[3][3] = { //female preference 
    {2,1,0}, 
    {0,1,2},
    {2,0,1}
  };
  
  for (int i = 0; i < col; i++) {
      if (q[i] == q[col]){
        return false;
    }
      if (mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i] < wp[q[col]][col] // CM NW < CM CW && NW CM < NW NW 
      || mp[col][q[i]] < mp[col][q[col]] && wp[q[i]][col] < wp[q[i]][i]) // NM CW < NM NW && CW NM < CW CM
        return false;
    }   
  return true; 
}


void backtrack(int q[], int &col){
    col--;//goes back a column
    if(col==-1){ //if it goes out of bounds on the left side after backtracking, stop with exit(1);
        exit(0); //terminates
    }
}
void print(int q[]){ //this is the function equivalent to goto print
    for(int i = 0; i < 3 ; i++){ //checks every column   
        cout << q[i] << " " ; // for women
    }
      cout << endl;
      for(int i = 0; i < 3 ; i++){
      cout << i << " " ; // for men
      }
      cout << endl;
}

int main(){ //int main has to do everything in a single sequence
  int q[8] = {}, col = 0; //set the array
  q[0] = 0; //far left one is set as 0 initially, like the goto version
  while(true){ // just an infinite loop made to be an infinite loop, it'll break when a condition is met or isn't
    col++; //goes to next column from the get-go
    if(col == 3) { //if columns are equal to 8, print and backtracl
      print(q);
      backtrack(q, col);
    } 
    else {
    q[col] = -1; //resets it to the top row
    }  
    while (true){ // loop
      q[col]++; // checks every row of the column
      if(q[col] == 3){ //if it goes through the entire column and every row doesn't work
        backtrack(q, col); //GOTO backtrack
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
