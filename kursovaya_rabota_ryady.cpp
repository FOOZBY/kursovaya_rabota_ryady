#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "en");
	double eps=0, x=0, result = 0, n = 0, facres = 1, sinusresult=0;//eps-погрешность,x-аргумент,result-результат,facres-результат факториала,n-член ряда
	string input="0";
	string::size_type sz;
	long long maxsteps=0,fac = 1,k=0;//maxsteps-максимальное количество членов ряда,fac-число от которого берём факториал
	char cont;//продолжить или нет

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	do {
		bool xgood = 1, epsgood = 1, stgood = 1;
		short key = 0, code = 0;
		while (xgood + epsgood + stgood)
		{
			do
			{
				system("cls");
				key = (key + 4) % 4;
				code = 0;
				if (key == 0)
					cout << ">Input an argument(x, radians)" << endl;
				else
					cout << "Input an argument(x, radians)" << endl;
				if (key == 1)
					cout << ">Input inaccuracy(eps)" << endl;
				else
					cout << "Input inaccuracy(eps)" << endl;
				if (key == 2)
					cout << ">Input the maximum number of row members(maxsteps)" << endl;
				else
					cout << "Input the maximum number of row members(maxsteps)" << endl;
				if (key == 3)
					cout << ">Exit" << endl;
				else
					cout << "Exit" << endl;
				if (xgood)
					cout << "x not inputed" << endl;
				else
					cout << "x = " << x << endl;
				if (epsgood)
					cout << "eps not inputed" << endl;
				else
					cout << "eps = " << eps << endl;
				if (stgood)
					cout << "maxsteps not inputed" << endl;
				else
					cout << "maxsteps = " << maxsteps << endl;
				if (code != 13) {
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
				while (xgood)
				{
					for (int i = 0; i < input.length(); i++)
						if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-')
						{
							cout << "invalid input,please repeat the input: ";
							cin >> input;
							i = -1;
						}
					xgood = 0;
				}
				x = stod(input, &sz);
			}
			break;
			case 1:
			{
				cout << endl << "Input inaccuracy(eps): ";
				cin >> input;
				while (epsgood)
				{
					for (int i = 0; i < input.length(); i++)
						if (!isdigit(input[i]) && input[i] != '.')
						{
							cout << "invalid input,please repeat the input: ";
							cin >> input;
							i = -1;
						}
					epsgood = 0;
				}
				eps = stod(input, &sz);
			}
			break;
			case 2:
			{
				cout << endl << "Input the maximum number of row members(maxsteps): ";
				cin >> input;
				while (stgood)
				{
					for (int i = 0; i < input.length(); i++)
						if (!isdigit(input[i]))
						{
							cout << "invalid input,please repeat the input: ";
							cin >> input;
							i = -1;
						}
					stgood = 0;
				}
				maxsteps = stoi(input, &sz);
			}
			break;
			case 3:
			{
				stgood = 0;
				epsgood = 0;
				xgood = 0;
				return 0;
			}
			break;
			}
		}
		system("cls");
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
				break;
			}
		}
		cout.precision(6);
		sinusresult = sin(x) / x;
		cout << "x = " << x << endl;
		cout << "eps = " << eps << endl;
		cout << endl << "Value of the function Sin(x)/x: " << sinusresult << endl;
		cout << endl << "Result: " << result << endl;
		cout << endl << "Amount of row members: " << k << endl;
		cout << "Do you want to continue? (Y(y) - Yes / Another key - No): ";
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');
}