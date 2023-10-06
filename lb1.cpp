#include <iostream>


using namespace std;


void getInfo() {
	cout << "1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool." << '\n';
	cout << "2) Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом." << '\n';
	cout << "3) Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок." << '\n';
	cout << "4) Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок." << '\n';
	cout << "0) Выход" << '\n';
	cout << "Выберите действие: ";
}


void getMemoryInfo() {
	cout << "\n";
	cout << "int: " << sizeof(int) << endl;
	cout << "short int: " << sizeof(short int) << endl;
	cout << "long int: " << sizeof(long int) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	cout << "char: " << sizeof(char) << endl;
	cout << "bool: " << sizeof(bool) << endl;
	cout << "\n";
}


void intToBin(int value) {

	unsigned int order = 32; // Количество разрядов
	unsigned int mask = 1 << order - 1; // Маска побитового сравнения
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		mask >>= 1; // Побитовый сдвиг маски
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}

}


void floatToBin(int integerA) {
	unsigned int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	bool f = true;
	for (int i = 1; i <= order; i++)
	{
		putchar(integerA & mask ? '1' : '0');
		mask >>= 1;
		if ((i % 9 == 0) && f)
		{
			putchar(' ');
			f = false;
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}

}


void doubleToBin(int integerA[2]) {
	unsigned int order = sizeof(int) * 8 * 2;
	unsigned int mask = 1 << order - 1;
	bool fSign = true, fOrder = true;
	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < 32; j++) {
			putchar(integerA[i] & mask ? '1' : '0');
			mask >>= 1;
			if ((j % 11 == 0) && fOrder && (j != 0))
			{
				putchar(' ');
				fOrder = false;
			}
			if ((j % order == 0) && fSign)
			{
				putchar(' ');
				fSign = false;
			}
		}
		mask = 1 << order - 1;
	}
}


void idz(int position, int& value) {
	srand(time(nullptr));
	int random_number = rand() % 2;
	if (random_number == 0) {
		unsigned int mask = (1 << position);
		value = value | mask;
	}
	else {
		unsigned int mask = (1 << position);
		mask = ~mask;
		value = value & mask;
	}
}


int main()
{
	int action;
	do
	{
		setlocale(0, "");
		getInfo();
		cin >> action;

		switch (action)
		{
		case 0:
			exit(0);
			break;
		case 1:
			getMemoryInfo();
			break;
		case 2:
			int value;
			cout << "Введите число (int): ";
			cin >> value;

			intToBin(value);

			cout << "\n\n";
			cout << "Какой бит поменять? ";
			int position;
			cin >> position;
			idz(position, value);
			intToBin(value);
			break;
		case 3:
		{
			union {
				int integerA;
				float floatB;
			};
			cout << "Введите число (float): ";
			cin >> floatB;

			floatToBin(integerA);

			cout << "\n\n";
			cout << "Какой бит поменять? ";
			int position;
			cin >> position;
			idz(position, integerA);
			floatToBin(integerA);
			break;
		}
		case 4:
		{
			union
			{
				int integerA[2];
				double doubleB;
			};
			cout << "Введите число (double): ";
			cin >> doubleB;

			doubleToBin(integerA);

			cout << "\n\n";
			cout << "Какой бит поменять? ";
			int position;
			cin >> position;


			if (position < 32) { idz(position, integerA[0]); }
			else { idz(position, integerA[1]); }

			doubleToBin(integerA);
			break;
		}
		default:
			cout << "Такого вариата нет!\n\n";
			break;
		}
		cout << "\n";
		system("pause");
		system("cls");

	} while (action != 0);
}