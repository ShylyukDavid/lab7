#include <iostream>
#include "Errors.h"

using namespace std;

Errors::Errors(int t) :typeOfException(t)
{

}

Errors::~Errors()
{

}

void Errors::Variety()
{
	cout << "You chose wrong variant. Please, choose one of the variety\n";
	cin.get();
}

void Errors::Number()
{
	cout << "You entered number out of limit\n";
}

void Errors::Limit()
{
	cout << "Incorrect entry. Try again: \n";
}

void Errors::Empty()
{
	cout << "Store has not materials\n";
}

void Errors::Notfound()
{
	cout << "Product not found\n";
}

void Errors::error() // вибір типу помилки
{
	switch (typeOfException)//<  визначити тип помилки
	{
	case 1:
	{
		Variety();
		break;
	}
	case 2:
	{
		Number();
		break;
	}
	case 3:
	{
		Limit();
		break;
	}
	case 4:
	{
		Empty();
		break;
	}
	case 5:
	{
		Notfound();
		break;
	}
	}
}