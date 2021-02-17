// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
using namespace std;

class Rat{
private:
   int n;
   int d;
   
public:
   // constructors
   
   // default constructor
   Rat(){
      n=0;
      d=1;
   }
   
   // 2 parameter constructor, what will be called in the main method
   Rat(int i, int j){
      n=i;
      d=j;
   }
   
   // conversion constructor (If only 1 parameter is imputted)
   Rat(int i){
      n=i;
      d=1;
   }
   
   //accessor functions (usually called get() and set(...) )
   int getN(){ //lets the privated int n be accessable 
      return n;
      }

   int getD(){ 
     return d;
     }
   
   void setN(int i){ // getters and setters make it possible to change the implementation without changing the interface.
      n=i;
      }

   void setD(int i){ 
     d=i;
     }
   
   //arithmetic operators
   Rat operator+(Rat r){ //for adding fractions
      Rat t;
      t.n = n*r.d + d*r.n;
      t.d = d*r.d;
      t.reduce(); //then the function is reduced further with the greatest common divisor (4/8 => 1/2)
      return t;
   }
   
   Rat operator-(Rat r){ //for subtracting
      Rat t;
      t.n = n*r.d - d*r.n;
      t.d = d*r.d;
      t.reduce();
      return t;
   }
   
   Rat operator*(Rat r){ //multiplication 
      Rat t;
      t.n = n*r.n;
      t.d = d*r.d;
      t.reduce();
      return t;
   }
   
   Rat operator/(Rat r){ //division
      Rat t;
      t.n = n*r.d;
      t.d = d*r.n;
      t.reduce();
      return t;
   }

    int gcd(int n, int d){ //finding the greatest common divisor through Euclid's algorithm
    if (n == 0){ 
        return d; 
    }
    return gcd(d % n, n); //returns the GCD which we'll need for the reduce function
} 

   // Reduce the Rat to lowest terms
   void reduce(){
      int thegcd = gcd(n, d); //sets this int to whatever the GCD for n, d is
      n = n/thegcd; //num divided by the GCD 
      d = d/thegcd; //dem divided by the GCD
      if (d < 0) { //Ensure that the denominator is postive by making the negatives cancel out
         d = -d;
         n = -n;
      }
   }
   
  

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
}; //end Rat


// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
istream& operator>>(istream& is, Rat& r){ // for reducing
   is >> r.n >> r.d; //kinda like cin
   r.reduce();
   return is;
}

//important to know that
// operator<<() is NOT a member function but since it was declared a friend of Rat it has access to its private parts.
// 6/5 is printed as 1 1/5
// Negative numbers are printed the same way, but beginning with a minus sign



//The ostream class has methods for formatting output, i.e. specifying scientific notation, fixed decimal notation, or a combination thereof, and for specifying the number of decimal digits displayed.
// The istream class has methods for detecting input errors and the end of input data.


ostream& operator<<(ostream& os, Rat r){ // for the improper fraction part
   r.reduce(); //it must first be reduced
   if (abs(r.n) >= r.d || r.n == 0) //if the numerator is larger than the denominator or is equal to zero
      os << r.n/r.d << " ";
   if (r.d != 1)
      os << (r.n/r.d <= -1 ? abs(r.n%r.d) : r.n%r.d) << "/" << r.d;
   return os;
}


int main() {
   Rat r1(7, 6), r2(4, 2); // (7/6) and (4/2)
   r1.setN(8); //this would change the numerator of fraction r1 to 8, so (8/4) for r1
   r2.setD(3); //
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;

   //r1.setN(3); //this would change the numerator of fraction r1
   //r2.setD(2); //this would do the same for the demoninator 
   //z=r1+r2;
   //cout<<z;

   return 0;
}


