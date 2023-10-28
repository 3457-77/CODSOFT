
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int number = 1+(rand()%100);
	bool isTrue = false;
	cout << "Hello to the NUMBER GUESSING GAME!!! \n";
	cout << "Enter the number\n";
	int num;
	cin >> num;
	while (!isTrue) {
		if (number == num)
		{
			cout << "Congrats, it's the correct number\n";
			break;
		}
		else if (number > num)
		{
			cout << "Too low\n";
		}
		else if (number < num)
		{
			cout << "Too high\n";
		}
		cout << "Try another guessing\n";
		cin >> num;
	}

	system("pause");
	return 0;

}

