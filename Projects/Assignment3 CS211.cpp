#include <iostream>
using namespace std;
int main() {
  int array[8][8] = {0};//sets a 8*8 array of 0's 
  int rows, columns = 0, count = 0;
  array[0][0] = 1; //1 is the queen
  next_column:
    columns++;
    if(columns == 8) 
         goto print;
    rows = -1; // set to -1 so when 1 is added it's on the first row of the next column (+1 it's 0)
  next_row:
    rows++;
    if(rows == 8)
      goto backtrack;
  //row testing
  for(int i = 0; i < columns; i++){ // checks if the rows contain a queen
    if(array[rows][i] == 1){
      goto next_row;
    } 
  }
  //up diagonal testing
  for(int i = 1; (rows - i) >= 0 && (columns - i) >= 0; i++){
    if(array[rows-i][columns-i] == 1){
      goto next_row; //try next row
    }
  }
  //down diagonal testing
  for(int i = 1; (rows + i) < 8 && (columns - i)>=0; i++){
  if(array[rows + i][columns - i] == 1){
    goto next_row; // try next row
    }
  }
  array[rows][columns] = 1; //if there's no row or diagonal conflict, print a 1 (queen)
    goto next_column;
  backtrack: //this checks from the back (RIGHT TO LEFT)
    columns--;//goes to previous columns
  if(columns == -1) // if the columns # reach the left side, stop it
    return 0;
  rows = 0;
  while(array[rows][columns] != 1){ //keeps going to the next row until there's a queen
  	rows++;
  }
  array[rows][columns] = 0; 
  goto next_row; 
  print:
    count++;
    cout << "Solution # " << count << endl;
    for(int i = 0; i < 8; i++){ //goes through the grid
    	for(int j = 0; j < 8; j++) { 
    		if(array[i][j] == 1)
        cout << "1"; //where conflicts don't exist
        else 
        cout << "0"; //where conflicts exist
        }
        cout << endl;
    }
	if(count < 92){
    cout << endl;
    cout << "Next";
    cout << endl;
	}	
    cout << endl;
    goto backtrack;
  return 0;   
  // I put a lot of notes to help myself understand the process better
}
