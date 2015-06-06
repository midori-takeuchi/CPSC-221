#include <iostream>

int main() {
  int x = 5;
  int y = 15;
  int* p1;
  int* p2;

  p1 = &x; 	// x contains 5; y=15; p1=&x; p2=undefined
  p2 = &y; 	// x contains 5; y=15; p1=&x; p2=&y

  *p1 = 6; 	// x contains 6; y=15; p1=&x; p2=&y 

  *p1 = *p2; 	// x=15; y=15; p1=&x; p2=&y

  p2 = p1;  	// x=15; y=15; p1=&x; p2=&x

  *p1 = *p2+10; // x=25; y=15; p1=&x; p2=&x

  return 0;
}
