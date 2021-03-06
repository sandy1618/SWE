// Doubt: why derived not callsed in the second instance.
#include <iostream>
#include <stdio.h>

using namespace std;

class Base
{
public:
	Base()
	{
		// note: fun() is virtual => What do you want to demonstrate here?
		fun();
	}
	virtual void fun()
	{
		cout << "\nBase Function";
	}
};

class Derived : public Base
{
	Base *a;
public:
	Derived() {
		cout << "Destructing";
		delete this;
		this -> a = new Base();
	}
  void fun() override
	{
		cout << "\nDerived Function";
	}
};

int main()
{
	// Base* pBase = new Derived();// base function
	Base *pBase = new Derived(); //DOUBT.  Also base function !!
	// Base* pBase = new Base() ; // Base fucntion
	// Derived *pBase1 = new Base() ; // error, as only base can be used.
	pBase -> fun();
	delete pBase;
	return 0;
}
