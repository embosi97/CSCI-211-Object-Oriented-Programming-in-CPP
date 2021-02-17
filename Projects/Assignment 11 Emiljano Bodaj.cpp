#include <iostream>
#include <cmath>
using namespace std;

double line(double x){
return x;
}

double square(double x){
return x*x;
}
   
double cube(double x){
return x*x*x;
} 

typedef double (*FUNC)(double);
double integrate(FUNC f, double a, double b) { //the integrate function is all we have to do for this assignment
  double sum; //must be a double because it'll be a decimal
  for (double i = a; i <= b; i = i + 0.0001) { //between a and b in increments of .0001. (in this case, a is 'from' and b is 'to')
    sum = sum + (0.0001 * f(i)); //Inside a loop we sum up the area of rectangles with a small base (say .0001) and height f(x) (I typed exactly this)
  }
  return sum;
}

int main() {
  
  cout << "The integral between 1 and 5 is: " << integrate(line, 1, 5)<<endl;
  cout << "The integral between 1 and 5 is (Squared): " << integrate(square, 1, 5) <<endl;
  cout << "The integral between 1 and 5 is (Cubed): " << integrate(cube, 1, 5) <<endl;
  
}
