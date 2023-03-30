#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
int main()
{
	int temperature = 63;
	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpos);	//if no is pos show + but only with base 10;
	cout << temperature << endl;

	cout << "For our programming friends, that's\n";
	cout << std::hex << temperature << endl;	//print int hex but whithout indicating base and small letter; 3f
	cout.setf(ios_base::uppercase);		// set to uppercase 3F;
	cout.setf(ios_base::showbase);		// show base 0x3f but upper set to 0X3F
	cout << "or\n";
	cout << temperature << endl;
	cout << "How " << true << "!  oops -- How ";	// true is printed as 1;
	cout.setf(ios_base::boolalpha);	//print true as true;
	cout << true << "!\n";
	return 0;
}