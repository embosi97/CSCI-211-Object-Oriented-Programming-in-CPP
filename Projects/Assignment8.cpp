#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


void print(int q[]) {
  
  int i, j, k, l;
  typedef char box[5][7];
  box bb, wb, *board[8][8];
  
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(241),' '      ,char(241),' '      ,char(241),' '      },
                     {' '      ,char(241),char(241),char(241),char(241),char(241),' '      },
                     {' '      ,char(241),char(241),char(241),char(241),char(241),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };
                     
  // fill in bb = black box and wb = white box
  for (i = 0; i < 5; i++)
    for (j = 0; j < 7; j++) 
    {
      wb[i][j] = ' ';
      bb[i][j] = char(219);
    }
    
   
  // fill board with pointers to bb and wb in alterate positions
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if ((i + j) % 2 == 0) {
        if (q[i] == j) {
          board[i][j] = &wq;
        } else {
          board[i][j] = &wb;
        }
      } else {
        if (q[i] == j) {
          board[i][j] = &bq;
        } else {
          board[i][j] = &bb;
        }
      }
       
  // print the board via the pointers in array board
  
  // first print the upper border
  cout << "   ";
    for (i = 0; i < 7 * 8; i++)
      cout << "_";
  cout << endl;
  
  // now print the board
  for (i = 0; i < 8; i++)
    for (k = 0; k < 5; k++)
    {
      cout << "   " << "|"; // print the left boarder
      for (j = 0; j < 8; j++)
        for (l = 0; l < 7; l++)
          cout << (*board[i][j])[k][l];
        cout << "|" << endl; // at end of line print bar and then newline  
    }
    
  // before exiting print lower border
  cout << "   ";
  for (i = 0; i < 7 * 8; i++)
    cout << "_";
  cout << endl;
  
}

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
    exit(0);
  q[c]++;  
  }
}

int main() {
  
  static int solution = 0;
  cout << "Solution # " << ++solution << ":" << endl;
  
  int q[8] = {}, c = 0;
  q[0] = 0;
  
    while (c >= 0) {
      c++;
      if (c == 8) {
        print(q);
        backtrack(q, c);
    } else {
        q[c] = -1;

    } while (c >= 0) {
      q[c]++;
        if (q[c] == 8) {
          backtrack(q, c);
        } else {
          if (isOk(q, c))
            break;
        }
        
    }
    
      
    }
     
  return 0;

}



