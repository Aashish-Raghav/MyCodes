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
	cout << n <<"\t" << n*n << " (decimal)\n";
	cout << std::hex;
	cout << n << "\t" << n*n << " (hexadecimal)\n";
	cout << std::oct;
	cout << n << "\t" << n*n << " (octal)\n";
	std::dec(cout);
	cout << n << "\t" << n*n << " (decimal)\n";
	return 0;
}