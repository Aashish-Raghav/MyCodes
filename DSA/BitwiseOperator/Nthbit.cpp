#include <iostream>
using namespace std;

//ACTIVATING............................................
// num is the number and pos is the position
// at which we want to set the bit.
void set(int & num,int pos)
{
	// First step is shift '1', second
	// step is bitwise OR
	num |= (1 << pos); 
}


//DEACTIVATIN..............................................
// First step is to get a number that has all 1's except the given position.
void unset(int &num,int pos)
{
	//Second step is to bitwise and this number with given number
	num &= (~(1 << pos));   //bitwise not is impt**
}



//ALTERING IF 0 -> 1  IF 1 -> 0...........................
// First step is to shift 1,Second step is to XOR with given
// number
void toggle(int& num, int pos) 
{ 
    num ^= (1 << pos); 
}


//checking Nth bit as set or unset.................................
bool at_position(int num, int pos)
{
	bool bit = num & (1 << pos);
	return bit;
}

//stripping off the last bit;
void strip_last_set_bit(int &num)
{
    num = num & (num-1);
}

//get the lowest set bit; also -num = 2's complement = 1's comp + 1 = ~num + 1;
int lowest_set_bit(int num)
{
    int ret = num & (-num);
    return ret;
}


int main()
{
	int num = 4;
	int pos = 1;
    set(num,pos);
    cout << num << endl;
    unset(num,pos);
    cout << num << endl;
	toggle(num, pos);
	cout << num << endl;
    
	return 0;
}
