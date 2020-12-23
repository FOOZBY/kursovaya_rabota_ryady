#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	long double eps,x,result = 0,n = 0,facres = 1;//eps-погрешность,x-аргумент,result-результат,facres-результат факториала,n-член ряда
	long long maxsteps,fac = 1,k;//maxsteps-максимальное количество членов ряда,fac-число от которого берём факториал
	char cont;//продолжить или нет
	do
	{
	system("cls");
	cout << "Введите аргумент(x,в радианах): ";
	cin >> x;
	cout << endl << "Введите погрешность(eps): ";
	cin >> eps;
	cout << endl << "Введите максимальное количество членов ряда(maxsteps): ";
	cin >> maxsteps;
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
	cout << endl << "Значение функции Sin(x)/x: " << sin(x) / x << endl;
	cout << endl << "Результат: " << result << endl;
	cout << endl << "Число шагов: " << k << endl;
	cout << "Желаете продолжить? (Y(y) - Да / Любая другая клавиша - Нет): ";
	cin >> cont;
	} while (cont == 'Y' || cont == 'y');
}