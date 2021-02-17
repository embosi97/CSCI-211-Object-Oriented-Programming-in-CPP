// recursive eight cross queens and stable marriage
#include <iostream>
#include <cmath>
using namespace std;
bool crossok(int * q, int col) { 
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

bool stableok(int q[], int col) {
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

void crossprint(int * q)
{ 
 static int count =0;
 cout << "Solution: " << ++count << endl << endl;

 for (int k=0; k<8; k++)
 cout<< q[k] << " ";
 cout<< endl << endl;
}
void stableprint(int q[]){ //this is the function equivalent to goto print
    cout << "For Women: ";
    for(int i = 0; i < 3 ; i++){ //checks every column   
        cout << q[i] << " " ; // for women
    }
      cout << endl;
      cout << "For Men: ";
      for(int i = 0; i < 3 ; i++){
      cout << i << " " ; // for men
      }
      cout << endl;
}
void crossmove(int* q, int i) // try place in col i
{
 if(i==8)
 {
 crossprint(q);
 return;
 }

 for(int j=0;j<8;j++) // j is the row value
 { q[i]=j;
 if(crossok(q,i)) // try and place a queen in row j of col i,if yes
 crossmove(q,i+1); // go to next column otherwise try next j
 }

 // no value of j worked so return;
};
void stablemove(int* q, int i) // try place in col i
{
 if(i==3)
 {
 stableprint(q);
 return;
 }

 for(int j=0;j<3;j++) // j is the row value
 { q[i]=j;
 if(stableok(q,i)) // try and place a queen in row j of col i,if yes
 stablemove(q,i+1); // go to next column otherwise try next j
 }
 // no value of j worked so return;
};
int main()
{
cout << "8 cross Recursion: " << endl << endl;
 int q[8];
 crossmove(q,0);
 cout << "************************************" << endl << endl;
 cout << "Stable Marriage Recursion: " << endl << endl;
 stablemove(q, 0);
 return 0;
} 

