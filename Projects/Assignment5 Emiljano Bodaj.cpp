#include <iostream>
#include <cmath> //for abs
using namespace std;

bool isOK(int q[], int col) { // 2 tests, different isOK than HW #4
int a[8][5] = { //the neighboring boxes of each corresponding box, 1 to 8. 
  {-1, -1, -1, -1, -1},  //box 0 has no neighbors             
  {0, -1, -1 , -1, -1},           
  {0, 1, -1, -1, -1},          
  {0, 2, -1, -1, -1},     
  {1, 2, -1, -1, -1},      
  {1, 2, 3, 4, -1},        
  {2, 3, 5, -1, -1},      
  {4, 5, 6, -1, -1}};

for (int i = 0; i < col; i++) { // checks up to but not including the current column
  if (q[i] == q[col]) {
  return false;
}
}
for (int i = 0; a[col][i] != -1; i++) { // keeps going as long as the column is not -1
  if (abs(q[col] - q[a[col][i]]) == 1) {
  return false;
  } 
  }
 return true;
}

void backtrack(int q[], int &col){
    col--;
    if(col == -1){ // out of bounds
        system("exit"); // terminates 
    }
}

void print(int q[]){    
          for(int i = 0; i < 8 ; i++){     
        cout << q[i] << "  " ;
    }
      cout << endl;
      cout << endl;
}

int main() {
  int q[8] = {}, col = 0;
  q[0] = 0;
  
  while(true){ //an unlimited loop that'll loop infinately until a condition is met
    col++;
    if(col == 8){
      print(q);
      backtrack(q, col); //it will print then backtrack
      } 
      else {
        q[col] = -1; //it will start are the top of the row of the current column
      }
  while(true){
    q[col]++; // advances to next row
    if(q[col] == 8){
      backtrack(q, col);
    }
    else {
        if (isOK(q, col) == true) {
          break; // breaks the current while loop if there's no conflict (if isOK is true)
        }
      }
    }      
    }
    return 0;
  }
