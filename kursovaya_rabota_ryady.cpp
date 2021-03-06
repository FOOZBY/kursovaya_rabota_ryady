﻿#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "en");
	double eps = 0, x = 0, result = 0, n = 0, facres = 1, sinusresult = 0;//eps-погрешность,x-аргумент,result-результат,facres-результат факториала,n-член ряда
	string input = "0";
	string::size_type sz;
	long long maxsteps = 0, fac = 1, k;//maxsteps-максимальное количество членов ряда,fac-число от которого берём факториал
	char cont;//продолжить или нет

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		n = 0;
		result = 0;
		facres = 1;
		fac = 1;
		k = 0;
		bool xbad = 1, epsbad = 1, stbad = 1;
		short key = 0, code = 0;
		do
		{
			system("cls");
			key = (key + 5) % 5;
			code = 0;
			cout << "x = " << x << endl;
			cout << "eps = " << eps << endl;
			cout << "maxsteps = " << maxsteps << endl;
			cout << endl;
			if (key == 0)
			{
				SetConsoleTextAttribute(descriptor, 14);
				cout << ">Input an argument(x, radians)" << endl;
				SetConsoleTextAttribute(descriptor, 7);
			}
			else
				cout << "Input an argument(x, radians)" << endl;
			if (key == 1)
			{
				SetConsoleTextAttribute(descriptor, 14);
				cout << ">Input inaccuracy(eps)" << endl;
				SetConsoleTextAttribute(descriptor, 7);
			}
			else
				cout << "Input inaccuracy(eps)" << endl;
			if (key == 2)
			{
				SetConsoleTextAttribute(descriptor, 14);
				cout << ">Input the maximum number of row members(maxsteps)" << endl;
				SetConsoleTextAttribute(descriptor, 7);
			}
			else
				cout << "Input the maximum number of row members(maxsteps)" << endl;
			if (key == 3)
			{
				SetConsoleTextAttribute(descriptor, 14);
				cout << ">Calculation" << endl;
				SetConsoleTextAttribute(descriptor, 7);
			}
			else
				cout << "Calculation" << endl;
			if (key == 4)
			{
				SetConsoleTextAttribute(descriptor, 14);
				cout << ">Exit" << endl;
				SetConsoleTextAttribute(descriptor, 7);
			}
			else
				cout << "Exit" << endl;
			cout << endl << "Navigation arrows(up and down) or W and S" << endl;
			if (code != 13)
			{
				code = _getch();
				if (code == 80 || code == 115)
					++key;
				if (code == 72 || code == 119)
					--key;
			}
		} while (code != 13);
		system("cls");
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		switch (key)
		{
		case 0:
		{
			cout << "Input an argument(x, radians): ";
			cin >> input;
			while (xbad)
			{
				for (int i = 0; i < input.length(); i++)
					if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-')
					{
						cout << "invalid input,please repeat the input: ";
						cin >> input;
						i = -1;
					}
				xbad = 0;
			}
			x = stod(input, &sz);
		}
		break;
		case 1:
		{
			cout << endl << "Input inaccuracy(eps): ";
			cin >> input;
			while (epsbad)
			{
				for (int i = 0; i < input.length(); i++)
					if (!isdigit(input[i]) && input[i] != '.')
					{
						cout << "invalid input,please repeat the input: ";
						cin >> input;
						i = -1;
					}
				epsbad = 0;
			}
			eps = stod(input, &sz);
		}
		break;
		case 2:
		{
			cout << endl << "Input the maximum number of row members(maxsteps): ";
			cin >> input;
			while (stbad)
			{
				for (int i = 0; i < input.length(); i++)
					if (!isdigit(input[i]))
					{
						cout << "invalid input,please repeat the input: ";
						cin >> input;
						i = -1;
					}
				stbad = 0;
			}
			maxsteps = stoi(input, &sz);
		}
		break;
		case 3:
		{
			if (eps <= 0)
			{
				cout << "Invalid value of eps" << endl;
				break;
			}
			if (maxsteps <= 0)
			{
				cout << "Invalid value of maxsteps" << endl;
				break;
			}
			cout << "x = " << x << endl;
			cout << "eps = " << eps << endl;
			cout << "maxsteps = " << maxsteps << endl << endl;

			for (k = 0; k < maxsteps; k++)
			{
				if (k > 0)
				{
					facres = facres * (fac + 1) * (fac + 2);
					fac += 2;
				}
				n = powl(-1, k) * powl(x, 2 * k) / facres;
				cout << k + 1 << ") gap = " << n << endl;
				result += n;
				cout << k + 1 << ") result = " << result << endl;
				if (abs(n) < abs(eps))
				{
					k++;
				}
			}
			cout << endl;
			cout.precision(6);
			sinusresult = sin(x) / x;
			cout << "Value of the function Sin(x)/x: " << sinusresult << endl;
			cout << "Result: " << result << endl;
			cout << "delta: " << abs(sinusresult - result) << endl;
			cout << "Amount of row members: " << k << endl << endl;
			allgood = 1;
		}
		break;
		case 4:
		{
			stbad = 0;
			epsbad = 0;
			xbad = 0;
			return 0;
		}
		break;
		}

		system("pause");
	} while (true);
}