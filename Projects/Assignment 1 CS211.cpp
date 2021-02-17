#include <iostream>
using namespace std;
long long sum() {
long long num1 = 0;
long long sum;
while (true) {
   sum = num1 * num1;
   if ((sum%2 != 0) && ((sum)/10)%2 != 0) {
   break;
   }
   num1++;
   }
  return sum;
}
int main() {
cout << " The full number is " << sum() << endl;
cout << " The last 2 odd digits numbers are " << sum()%10 << " and " << ((sum()/10)%10) << endl;
}
