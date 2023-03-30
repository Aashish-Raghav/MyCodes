//getline(char *,int,char)
//getline(char *,int)  char = '\n' by default 
//get(char *,int,char)
//get(char *,int)  char = '\n' by default 
//get()
//ignore(int,char)

#include <iostream>
const int Limit = 255;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char input[Limit];

	cout << "Enter a string for getline() processing:\n";
	cin.getline(input,Limit,'#');	//reads and discard the delimiter
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 1\n";

	char ch;
	cin.get(ch);	// OR ch = cin.get();
	cout << "The next input character is " << ch << endl;

	if (ch != '\n')
	{
		cin.ignore(Limit,'\n');	//ignore() just read the character
								//  to limit or delimiter and ignores them
	}

	cout << "Enter a string for get() processing:\n";
	cin.get(input,Limit,'#');		// donot read delimiter;
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 2\n";

	ch = cin.get();
	cout << "The next input character is " << ch << endl;

	return 0;
}