#include<iostream>
using namespace std;

//simple calculator
//name - Leonardo Marcu

class Calculator
{
private:
	int a, b;
	char sign, op;
public:

	Calculator()
	{
		this->sign = 'y';
	}

	void input()
	{
		cout << "Enter first number: "; cin >> a;
		cout << "Enter second number: "; cin >> b;
		cout << "Enter operator(+,-,/,*): "; cin >> op;
	}

	int add()
	{
		return a + b;
	}

	int subtract()
	{
		return a - b;
	}

	int multiply()
	{
		return a * b;
	}

	int division()
	{
		return a / b;
	}

	void calc()
	{
		while (sign == 'y')
		{
			input();
			switch (op)
			{
			case '+':
				cout << a <<" + " << b <<" = "<<add();
				break;
			case '-':
				cout << a << " - " << b << " = " << subtract();
				break;
			case '*':
				cout << a << " * " << b << " = " << multiply();
				break;
			case '/':
				cout << a << " / " << b << " = " << division();
				break;
			default:
				cout << "\nInvalid Entry, please try again." << endl;
			}

			cout << endl;
			cout << "\nDo you wanna continue another calculation?(y/n): ";
			cin >> sign;
		}
	}
};

int main()
{
	Calculator c;
	c.calc();
}