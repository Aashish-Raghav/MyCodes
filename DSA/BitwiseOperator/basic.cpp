#include<iostream>
/*
1. The & (bitwise AND) in C or C++ takes two numbers as operands and does AND on every bit of two numbers. 
   The result of AND is 1 only if both bits are 1.  
2. The | (bitwise OR) in C or C++ takes two numbers as operands and does OR on every bit of two numbers.
    The result of OR is 1 if any of the two bits is 1. 
3. The ^ (bitwise XOR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers.
   The result of XOR is 1 if the two bits are different. 
4. The << (left shift) in C or C++ takes two numbers, left shifts the bits of the first operand, 
   the second operand decides the number of places to shift. 
5. The >> (right shift) in C or C++ takes two numbers, right shifts the bits of the first operand,
   the second operand decides the number of places to shift. 
6. The ~ (bitwise NOT) in C or C++ takes one number and inverts all bits of it.    

*/
using namespace std;
int main(){

	// a = 5(00000101), b = 9(00001001)
	int a = 5, b = 9;

	// The result is 00000001 = 1
	cout<<"a = " << a <<","<< " b = " << b <<endl;
	cout << "a & b = " << (a & b) << endl;

	// The result is 00001101 = 13
	cout << "a | b = " << (a | b) << endl;

	// The result is 00001100 = 12
	cout << "a ^ b = " << (a ^ b) << endl;

	// The result is 11111010 = -6    how? (2's complement le toh shayad baat ban jae..........)
	cout << "~a = " << (~a) << endl;

	// The result is 00010010 = 18
	cout<<"b << 1" <<" = "<< (b << 1) <<endl;

	// The result is 00000100 = 4
	cout<<"b >> 1 "<<"= " << (b >> 1 )<<endl;
   cout << (6 | 2) << endl;
    return 0;
}

//IMPORTANT POINTS:
/*
1.The left shift and right shift operators should not be used for negative numbers.
2.Interestingly!! The bitwise OR of two numbers is just the sum of those two numbers
 if there is no carry involved, otherwise you just add their bitwise AND.
3. The left-shift and right-shift operators are equivalent to 
  multiplication and division by 2 respectively
3.The bitwise XOR operator is the most useful operator from a technical interview perspective.
*/