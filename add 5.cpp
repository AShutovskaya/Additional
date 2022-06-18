#include <iostream>
using namespace std;

class Foo
{
public:

	Foo(int j) 
	{
		i = new int[j]; 
		cout << "Foo constructor" << endl;

	}
	virtual ~Foo() 
	{ 
		delete i;
		cout << "Foo destructor" << endl;
	}
private:
	int* i;
};
class Bar : public Foo//добавлен public
{
public:
	Bar(int j):Foo(j)// добавлено : Foo(j)
	{
		i = new char[j];
		cout << "Bar constructor" << endl;
	}
	~Bar()
	{
		delete i;
		cout << "Bar destructor" << endl;
	}
private:
	char* i;
};




int main()// void -> main
{
	Foo* f = new Foo(100);
	Bar* b = new Bar(200);

	delete[] f;
	delete[] b;

	

	return 0;


}
