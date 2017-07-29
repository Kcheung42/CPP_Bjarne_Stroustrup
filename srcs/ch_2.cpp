#include <iostream>
#include "main.h"

using namespace std;

// "Chapter 2"
double square(double x)
{
	return (x*x);
}

void	print_square(double x)
{
	cout << "the square of " << x << " is " << square(x) << "\n";
}

// Using Switch Statements
bool accept2()
{
	cout << "Do you want to proceed ( y or n)?\n";

	char answer = 0;
	cin >> answer; // read answer

	switch (answer) {
		case 'y':
			return (true);
		case 'n':
			return (false);
		default:
			cout << "I'll take that for a no.\n";
			return (false);
	}
}

// int main(){
// 	accept2();
// }

// Introducing Loops
bool accept3()
{
	int tries = 1;
	while (tries<4)
	{
		cout << "Do you want to proceed (y or n)?\n";
		char answer = 0;
		cin >> answer;
		switch(answer){
		case 'y':
			cout << "YES!? ok thats fine\n";
			return true;
		case 'n':
			cout << "No? ok thats fine\n";
			return (false);
		default:
			cout << "Sorry, I don't understand that.\n";
			++tries;
		}
	}
	cout << "I'll take that for a no.\n";
	return (false);
}

// int main(){
// 	accept3();
// }

// Copying from one Array to another
void copy_fct()
{
	int v[10] = {0,1,2,3,4,5,6,7,8,9};
	int v2[10];

	for (auto i = 0; i < 10; ++i) {
		v2[i] = v[i] * 2;
	}

	// print
	for (auto i = 0; i < 10; ++i) {
		cout << v2[i] << " ";
	}
}

// int main(){
// 	copy_fct();
// }

// Ways to print an array
void print()
{
	int v[] = {0,1,2,3,4,5,6,7,8,9};

	for (auto x : v)
		cout << x << '\n';

	for (auto x : {10, 21,22,34,53})
		cout << x << '\n';
		
}

// int main(){
// 	print();
// }

// Introduce & declarator operators
void increment()
{
	int v[] = {0,1,2,3,4,5,6,7,8,9};

	for (auto &x : v) {
		++x;
	}
	for (auto i : v)
		cout << i;
}

// int main(){
// 	increment();
// }

int count_x(char *p, char x)
{
	if(p == nullptr) return 0;
	int count = 0;
	for (; *p != 0; ++p) // leave out initializer if we dont need it
		if(*p == x)
			count++;
	cout << count << '\n';
	return count;
}

// int main()
// {
// 	char p[12] = "abcdefeeeee";
// 	char x = 'e';
// 	count_x(p,x);
//
// }

void vector_init(Vector& v, int s)
{
	v.elem = new double[s]; // allocate an arrayb of s doubles 
	v.sz = s;
}

// int main()
// {
// 	Vector v;
// 	vector_init(v, 10);
// }

// Introducing Class
// class Vector_2
// {
// 	public:
// 		Vector_2(int s) :elem{new double[s]}, sz{s}{} // Constructor, initialize elem to array and sz to 's'
// 		double &operator[](int i){
// 			return elem[i];
// 		}
//
// 		int size(){return sz;}
//
// 	private:
// 		double *elem;
// 		int sz;
// };

double read_and_sum(int s)
{
	Vector_2 v(s);
	for(int i = 0; i != v.size(); i++)
		cin >> v[i];

	double sum = 0;
	for (int i = 0; i != v.size() ; i++)
		sum += v[i];
	return sum;
}

// int main(){
//
// 	 read_and_sum(5);
// }

// 2.3.3 Enumerations

enum class Color {red, blue, green};
enum class Traffic_light{green, yellow, red};

// 2.4.1 Seperate Compilation
// Interface is defined in the main.h file
// functions for the Interface can be defined here

// Vector_2::Vector_2(int s) :elem{new double[s]}, sz{s} //constructor
// {}

// edit: 2.4.3.2 Invariants
Vector_2::Vector_2(int s){
	if (s < 0) throw length_error{"out of range"};
	elem = new double[s];
	sz = s;
}

double &Vector_2::operator[](int i){
	if (i < 0 || size() <= i) // edit from 2.4.3.1 Exception
	{
		throw out_of_range("Vector::operator[]");
	}
	return (elem[i]);
}

int Vector_2::size(){
	return (sz);
}

// 2.4.3.1 Exceptions

void f(Vector_2 &v)
{
	try{
		v[v.size()] = 7;
	}
	catch (out_of_range)
	{
		cout << "out of range\n";
	}
}

// int main()
// {
// 	Vector_2 v(10);
// 	f(v);
// }

// 2.4.3.2 Invariants
// 
// def:A statement of what is assumed to be true for a class
// Consider Vector v(-27) ; 

void test()
{
	try{
		Vector_2 v(-27);
	}
	catch (length_error){
		cout << "out of range\n";
		//handle negative size
	}
	catch (bad_alloc){
		cout << "not enough memory\n";
		//handle memory exhaustion
	}
}

// int main()
// {
// 	test();
// }

// 2.4.3.3 Static Assertions

constexpr double C = 299792.458;
void f(double speed){
	const double local_max = 160.0/(60 * 60);

	static_assert(speed < C, "can't go that fast");
	static_assert(local_max < C, "can't go that fast");
}

int main(){
	f(100);
}


// int main()
// {
// 	cout << "Hello World!\n";
//
// 	 // read_and_sum(5);
// 	 Color col = Color::red;
// 	 Traffic_light light = Traffic_light::red;
//
// 	return (0);
// }
