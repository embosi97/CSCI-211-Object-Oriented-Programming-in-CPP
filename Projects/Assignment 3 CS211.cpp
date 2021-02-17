#include <iostream>
using namespace std;
int main() {
  int array[8][8] = {0}; 
  int rows = 0, columns = 0, count = 0;//sets a 8*8 array of 0's
  array[0][0] = 1; //1 is the queen
  next_column:
    columns++;
    if(columns == 8) 
         goto print;
    rows = -1; // set to -1 so when 1 is added it's on the first row (+1 it's 0)
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
      goto next_row;
    }
  }
  //down diagonal testing
  for(int i = 1; (rows + i) < 8 && (columns - i)>=0; i++){
  if(array[rows + i][columns - i] == 1){
    goto next_row;
    }
  }
  array[rows][columns] = 1;
    goto next_column;
  backtrack:
    columns--;
  if(columns == -1)
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
    for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 8; j++) {
    		if(array[i][j] == 1)
        cout << "F";
        else 
        cout << "E";
        }
        cout << endl;
    }
	if(count < 92){
    cout << "Next";
	}	
    cout << endl;
    goto backtrack;
  return 0;   
}

