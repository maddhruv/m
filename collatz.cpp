#include <iostream>
/*----------Collatz conjecture----------------------
------------Take any positive integer n. If n is even,
------------divide it by 2 to get n / 2. If n is odd,
------------multiply it by 3 and add 1 to obtain 3n + 1.
------------https://en.wikipedia.org/wiki/Collatz_conjecture*/
using namespace std;

int main(){
  int n, result, i{0};
  cout<<"Prints the hailstone sequence for any positive whole number:\n";
  cin>>n;
  while(i<11){
    cout<<n<<", ";
    if(n%2==0)
      n = n/2;
    else
      n = 3*n+1;
    i++;
  }
  return 0;
}
