

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	cout << "Hello to CALCULATOR... \n";
	double num1, num2;
	char c;
	cout << "Enter 2 numbers\n";
	cout << "The first number: ";
	cin >> num1;
	cout << "The second number: ";
	cin >> num2;
	cout << "Choose the Operation you need  - + * / \n";
	cin >> c;

	switch (c) {
	case ('+'): cout << num1 << " + " << num2 << " = " << num1 + num2;

		break;
	case ('-'): cout << num1 << " - " << num2 << " = " << num1 - num2;
		break; 
	case ('*'): cout << num1 << " * " << num2 << " = " << num1 * num2;
		break;
	case ('/'): cout << num1 << " / " << num2 << " = " << num1 / num2;
		break;
	default:
		cout << "Sorry, Unavailable operation\n";
	
	}

}

