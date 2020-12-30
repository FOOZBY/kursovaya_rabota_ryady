#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "en");
	double eps, x, result = 0, n = 0, facres = 1, sinusresult;//eps-погрешность,x-аргумент,result-результат,facres-результат факториала,n-член ряда
	string input;
	string::size_type sz;
	long long maxsteps,fac = 1,k;//maxsteps-максимальное количество членов ряда,fac-число от которого берём факториал
	char cont;//продолжить или нет
	bool good = 1;
	do
	{
	system("cls");
	cout << "Input an argument(x, radians): ";
	cin >> input;
	while (good)
	{
		for (int i = 0; i < input.length(); i++)
			if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-')
			{
				cout << "invalid input,please repeat the input: ";
				cin >> input;
				i = 0;
			}
		good = 0;
	}
	x = stod(input,&sz);
	cout << endl << "Input inaccuracy(eps): ";
	cin >> input;
	good = 1;
	while (good)
	{
		for (int i = 0; i < input.length(); i++)
			if (!isdigit(input[i]) && input[i] != '.')
			{
				cout << "invalid input,please repeat the input: ";
				cin >> input;
				i = 0;
			}
		good = 0;
	}
	eps = stod(input, &sz);
	cout << endl << "Input the maximum number of row members(maxsteps): ";
	cin >> input;
	good = 1;
	while (good)
	{
		for (int i = 0; i < input.length(); i++)
			if (!isdigit(input[i]))
			{
				cout << "invalid input,please repeat the input: ";
				cin >> input;
				i = 0;
			}
		good = 0;
	}
	maxsteps = stoi(input, &sz);
	for (k = 0; k < maxsteps; k++)
	{
		if (k > 0)
		{
			facres = facres * (fac + 1) * (fac + 2);
			fac += 2;
		}
		n = powl(-1, k) * powl(x, 2 * k) / facres;
		result += n;
		if (abs(n) < abs(eps))
		{
			k++;
			break;
		}
	}
	cout.precision(6);
	sinusresult = sin(x) / x;
	cout << endl << "Value of the function Sin(x)/x: " << sinusresult << endl;
	cout << endl << "Result: " << result << endl;
	cout << endl << "Amount of row members: " << k << endl;
	cout << "Do you want to continue? (Y(y) - Yes / Another key - No): ";
	cin >> cont;
	} while (cont == 'Y' || cont == 'y');
}