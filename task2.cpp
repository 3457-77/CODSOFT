

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	bool isTrue = true;
	double fahrenheit = 0;
    double celsius = 0;

	cout << "Welcome to the Temperature converter program!!\n";
	cout << "Enter 1 to covert Fahrenheit to Celsius.\nEnter 2 to covert Celsius to Fahrenheit." << endl;
	int num; double t;
	cin >> num;

	while (isTrue) {

		if (num != 1 && num != 2 && num!=3) {
			cout << "Wrong input\nPlease enter 1 or 2 or 3 to Exit: ";
			cin >> num;
		}
		else isTrue = false;
		if (num == 3)
			break;
	}
	if (num == 3)
		return 0;

	cout << "Enter the Temperature: ";
	cin >> t;

	if (num == 1) {
		double f = t;
		celsius = (f - 32) * (5.0 / 9.0);
		cout << "Temperature in Celsius: "<<celsius;
	}

	else if (num == 2) {
		double c = t;
		fahrenheit = c * (9.0 / 5.0) + 32;
		cout << "Temperature in Fahrenheit: "<<fahrenheit;
	}	

}