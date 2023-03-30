#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	cout << "Enter an integer: ";
	int n;
	cin >> n;
	cout << "n\tn*n\n";

    //default decimal mode
	cout << n <<"\t" << n*n << " (decimal)\n";

    //set to hexadecimal mode
	cout << std::hex;
	cout << n << "\t" << n*n << " (hexadecimal)\n";

    //set to octal mode
	cout << std::oct;
	cout << n << "\t" << n*n << " (octal)\n";

    //alternative way to call manipulator
	std::dec(cout);
	cout << n << "\t" << n*n << " (decimal)\n";
	return 0;
}