#include <iostream>
#include <iomanip>
using namespace std;




// table;
int main()
{
	/*
	int num;
	cin >> num;
	for (int i = 1;i <= num;i++){
		for (int j = 1;j <= 10;j++)
			cout << setw(3) << i*j << " ";
		cout << endl;
	}
	*/

	int count = 0;
	// //pattern;
	// for (int i = 1;i <= 5;i++)	//printing rows;
	// {
	// 	for (int i = 1;i < )
	// }
}

// template <class T>
// class HasFriend
// {
// private:
// 	T item;
// 	static int ct;
// public:
// 	HasFriend(const T & i) : item(i) {ct++;}
// 	~HasFriend() {ct--;}
// 	friend void count();	// non template friend fxn;
// 	friend void report(HasFriend<T> &); 	//template parameter;	
// };

// //each specialisation has its own static data member;
// template <class T>
// int HasFriend<T>::ct = 0;

// //non template friend function;
// void count()
// {
// 	cout << "int count : " << HasFriend<int>::ct << "; ";
// 	cout << "double count : " << HasFriend<double>::ct << endl;
// }

// //non template friend fxn with template parameter each has to 
// // be declared individually;
// void report(HasFriend<int> & hf)
// {
// 	cout << "HasFriend<double>: " << hf.item << endl;
// }

// void report(HasFriend<double> & hf)
// {
// 	cout << "HasFriend<double>: " << hf.item << endl;
// }

// int main()
// {
// 	cout << "No objects declared: ";
// 	count();
// 	HasFriend<int> hfi1(10);
// 	cout << "After hfi1 declared: ";
// 	count();
// 	HasFriend<int> hfi2(20);
// 	cout << "After hfi2 declared: ";
// 	count();
// 	HasFriend<double> hfdb(10.5);
// 	cout << "After hfdb declared: ";
// 	count();
// 	report(hfi1);
// 	report(hfi2);
// 	report(hfdb);

// 	return 0;
// }






// #include <iostream>
// #include <cstdlib>
// template <class T,int n>
// class ArrayTP
// {
// private:
// 	T ar(n);
// public:
// 	ArrayTp() {};
// 	explicit ArrayTP(const T & v);
// 	virtual T & operator[](int i);
// 	virtual T operator[](int i) const;
// };

// template <class T,int n>
// ArrayTP<T,n>::ArrayTP(const T & v)
// {
// 	for (int i = 0; i < n;i++)
// 	{
// 		ar[i] = v;
// 	}
// }

// template <class T,int n>
// T & ArrayTP<T,n>::operator[](int i)
// {
// 	if (i < 0 || i >= n)
// 	{
// 		std::cerr << "Error in array limits: " << i	
// 			 << " is out of range\n";
// 		std::exit(EXIT_FAILURE);
// 	}
// 	return ar[i];
// }

// template <class T,int n>
// T  ArrayTP<T,n>::operator[](int i) const
// {
// 	if (i < 0 || i >= n)
// 	{
// 		std::cerr << "Error in array limits: " << i	
// 			 << " is out of range\n";
// 		std::exit(EXIT_FAILURE);
// 	}
// 	return ar[i];
// }








// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// const int Num = 10;
// template <class Type>
// class Stack
// {
// private:
// 	static const int SIZE = 10;
// 	int stacksize;
// 	Type* items;
// 	int top;
// public:
// 	Stack(const Stack & st);
// 	explicit Stack(int ss = SIZE);
// 	~Stack() { delete [] items;}
// 	bool isempty() { return top == 0;}
// 	bool isfull() { return top == stacksize; }
// 	bool push(const Type & item);
// 	bool pop(Type & item);
// 	Stack & operator=(const Stack & st);
// };

// template<class Type>
// Stack<Type>::Stack(const Stack & st)
// {
// 	stacksize = st.stacksize;
// 	top = st.top;
// 	items = new Type [stacksize];
// 	for (int i = 0;i < top;i++)
// 	{
// 		items[i] = st.items[i];
// 	}
// }

// template <class Type>
// Stack<Type>::Stack(int ss) : stacksize(ss),top(0)
// {
// 	items = new Type[stacksize];
// }

// template < class Type>
// bool Stack<Type>::push(const Type & item)
// {
// 	if (top < stacksize) 
// 	{
// 		items[top++] = item;
// 		return true;
// 	}
// 	return false;
// }
// template <class Type>
// bool Stack<Type>::pop(Type & item)
// {
// 	if (top > 0)
// 	{
// 		item = items[--top];
// 		return true;
// 	}
// 	return false;
// }

// template <class Type>
// Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
// {
// 	if (this == &st)
// 		return *this;
// 	delete [] items;
// 	stacksize = st.stacksize;
// 	top = st.top;
// 	for (int i = 0;i < top;i++)
// 		items[i] = st.items[i];
// 	return *this;
// }

// int main()
// {
// 	std::srand(std::time(0));	//randomize rand();
// 	std::cout << "Please Enter Stack Size : ";
// 	int ss;
// 	std::cin >> ss;
// 	Stack<const char *> st(ss);
// 	const char * in[Num] ={
// 		"1: A","2: B","3: C","4: D","5: E",
// 		"6: F","7: G","8: H","9: I","10: J"
// 	};

// 	const char * out[Num];

// 	int processed = 0;
// 	int nextin = 0;
// 	while (processed < Num)
// 	{
// 		if (st.isempty())
// 		{
// 			st.push(in[nextin++]);
// 			std::cout << 1 << std::endl;
// 		}
// 		else if (st.isfull())
// 		{
// 			st.pop(out[processed++]);
// 			std::cout << 2 << std::endl;
// 		}
// 		else if (std::rand() % 2 && nextin < Num)
// 		{	
// 			st.push(in[nextin++]);
// 			std::cout << 3 << std::endl;
// 		}
// 		else 
// 		{
// 			st.pop(out[processed++]);
// 			std::cout << 4 << std::endl;
// 		}
// 	}
// 	for (int i = 0;i < Num;i++)
// 	{
// 		std::cout << out[i] << std::endl;
// 	}

// 	std::cout << "Bye\n";
// 	return 0;
// }


// #include <string>
// #include<iostream>
// using namespace std;
// static int nStudent = 1;
// static int nProfessor = 1;
// static const int Size = 6;
// class Person
// {
// protected:
// 	string name;
// 	int age;
// public:
// 	Person(const string s = "null",int a = 0);
// 	virtual ~Person() {}
// 	virtual void getdata();
// 	virtual void putdata();
// };

// Person::Person(const string s,int a)
// {
// 	name = s;
// 	age = a;
// }

// void Person::getdata()
// {
// 	cin >> name;
// 	cin >> age;
// }

// void Person::putdata()
// {
// 	cout << name << " " << age << " ";
// }

// class Professor : public Person
// {
// private:
// 	int publications;
// 	int cur_id;
// public:
// 	Professor(const string s = "Null",int a = 0);
// 	virtual ~Professor() {}
// 	virtual void getdata();
// 	virtual void putdata();
// };

// Professor::Professor(const string s,int a) : Person(s,a)
// {
// 	cur_id = nProfessor++;
// }

// void Professor::getdata()
// {
// 	Person::getdata();
// 	cin >> publications;
// }

// void Professor::putdata()
// {
// 	Person::putdata();
// 	cout << publications << " " << cur_id << endl;
// }

// class Student : public Person
// {
// private:
// 	int marks[Size];
// 	int cur_id;
// public:
// 	Student(const string s = "Null",int a = 0);
// 	virtual ~Student() {}
// 	virtual void getdata();
// 	virtual void putdata();
// };

// Student::Student(const string s,int a) : Person(s,a)
// {
// 	cur_id = nStudent++;
// }

// void Student::getdata()
// {
// 	Person::getdata();
// 	for (int i = 0;i < Size;i++)
// 		cin >> marks[i];
// }

// void Student::putdata()
// {
// 	Person::putdata();
// 	int sum = 0;
// 	for (int i = 0;i < Size;i++)
// 	{
// 		sum += marks[i];
// 	}
// 	cout << sum << " " << cur_id << endl;
// }



// int main() 
// {
// 	// Person a;
// 	// a.putdata();
// 	// a.getdata();
// 	// a.putdata();
// 	// cout << endl;

// 	// Professor p;
// 	// p.putdata();
// 	// p.getdata();
// 	// p.putdata();
// 	// cout << endl;

// 	// Professor p1;
// 	// p1.putdata();
// 	// p1.getdata();
// 	// p1.putdata();

// 	Student s1;
// 	s1.putdata();
// 	s1.getdata();
// 	s1.putdata();
// }