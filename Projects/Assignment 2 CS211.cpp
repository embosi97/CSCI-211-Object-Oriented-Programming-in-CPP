#include <iostream>
using namespace std;
bool equalARR(int a[], int b[], int num) {
int count = 0;
for(int s = 0; s < num; s++) {
for(int i = 0; i < num; i++){
if (a[i] == b[(i+s)%num]){ //checks if it fits the condition
count++;
if(count == num) { //if the entire array fits the condition then it's true
return true;
}
}
else {    
count = 0; //reset it to zero
break; //stop loop
}
}   
}
return false;
}
int main() {
cout << boolalpha;
bool equalARR(int a[], int b[], int num);  
int first[] = {1, 2, 3, 4, 5};
int second[] = {3, 4, 5, 1, 2};
cout << " Are they equivalent shifts?: " << equalARR(first, second, 5) << endl; //calling the function
int third[] = {5, 3, 4, 6, 7};
int fourth[] = {3, 8, 7, 5, 3};
cout << " How about these?: " << equalARR(third, fourth, 5) << endl; 
int fifth[] = {6, 7, 8, 9, 10};
int sixth[] = {8, 9, 10, 6, 7};
cout << " Lastly, these?: " << equalARR(fifth, sixth, 5) << endl;
return 0;
}
