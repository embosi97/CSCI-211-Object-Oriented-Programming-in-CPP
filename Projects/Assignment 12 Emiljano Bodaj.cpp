#include <iostream>
#include <vector>
using namespace std;


int main() {
  
  vector<int> t[3]; // 3 towers
  int n;
  cout << "Enter the number of rings to move: ";
  cin >> n;
  cout << endl;
  
  int from = 0, candidate = 1, move = 0, to; // 'from' is the first tower, the second one is 'to'
  if (n % 2 != 0) // 'from' is at 0
    to = 1;
  else 
    to = 2;
  
  for (int i = n + 1; i >= 1; --i)  //Initialize the towers
  t[0].push_back(i);
  t[1].push_back(n+1);
  t[2].push_back(n+1);
    
  while (t[1].size() < n+1) {
    cout << "Change #" << ++move << " ring " << candidate << " from  " << char(from+'A')
    << " to " << char(to+'A') << endl;
    
    t[to].push_back(t[from].back()); //moving the discs 
    t[from].pop_back();
    
    if (t[(to+1)%3].back() < t[(to+2)%3].back()){ //from
      from = (to+1)%3;
  }
    else {
      from = (to+2)%3;
  } 
    candidate = t[from].back();  //candidate is updated 
  
    if (n % 2 != 0) { // to
      if (candidate < t[(from+1) % 3].back())
      to = (from+1)%3;
    else
      to = (from+2)%3;
    }
    if (n % 2 == 0) {
      if (candidate < t[(from+2) % 3].back())
      to = (from+2)%3;
    else 
      to = (from+1)%3; 
    }

  }
  
  return 0;
  
}
