#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;


void menu() {
	cout << "1) Создать целочисленный массив размерности N = 100. Элементы массивы принимают случайное значение в диапазоне от -99 до 99.\n2) Отсортировать  массив (от меньшего к большему). Определить время, затраченное на сортировку.\n3) Найти максимальный и минимальный элемент массива. Подсчитать время поиска этих элементов в отсортированном массиве и неотсортированном.\n4)Выводит среднее значение максимального и минимального значения в отсортированном и неотсортированном. Вывести индексы всех элементов, которые равны этому значению, и их количество. Подсчитать время поиска.\n5)Вывести количество элементов в отсортированном массиве, которые меньше числа a.\n6)Вывести количество элементов в отсортированном массиве, которые больше числа b.\n7)binsearch\n8)Поменять местами элементы массива, индексы которых вводит пользователь. Подсчитать скорость обмена.\n9)Показать массив.\n10)ИДЗ\n0)Выход\n";
}


void showArray(int list[], int N) {
	for (int i = 0; i < N; i++) {
		cout << list[i] << " ";
	}
}


void quickSort(int list[], int N) {
	int i = 0;
	int j = N - 1;
	int mid = list[N / 2];

	do {
		while (list[i] < mid) {
			i++;
		}
		while (list[j] > mid) {
			j--;
		}

		if (i <= j) {
			int tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		quickSort(list, j + 1);
	}
	if (i < N) {
		quickSort(&list[i], N - i);
	}
}


void bubbleSort(int list[], int N)
{
	int i, j;
	bool swapped;
	for (i = 0; i < N - 1; i++) {
		swapped = false;
		for (j = 0; j < N - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}


void shakerSort(int list[], int N)
{
	bool swapped = true;
	int start = 0;
	int end = N - 1;

	while (swapped) {
		swapped = false;
		for (int i = start; i < end; ++i) {
			if (list[i] > list[i + 1]) {
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}

		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i) {
			if (list[i] > list[i + 1]) {
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}


int getNextGap(int gap)
{
	gap = (gap * 10) / 13;
	if (gap < 1)
		return 1;
	return gap;
}
void combSort(int list[], int N)
{
	int gap = N;
	bool swapped = true;

	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);
		swapped = false;

		for (int i = 0; i < N - gap; i++)
		{
			if (list[i] > list[i + gap])
			{
				swap(list[i], list[i + gap]);
				swapped = true;
			}
		}
	}
}


void insertSort(int list[], int N) {
	int i, key, j;
	for (i = 1; i < N; i++) {
		key = list[i];
		j = i - 1;

		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}


void findMinMax(int* max, int* min, int list[], int N) {
	for (int i = 0; i < N; i++) {
		list[i] >= *max ? *max = list[i] : *max = *max;
		list[i] <= *min ? *min = list[i] : *min = *min;
	}
	cout << "Максимальный элемент: " << *max << "\nМинимальный элемент: " << *min;
}


void findAverage(bool isSorted, int max, int min, int list[], int N) {
	int average = (max + min) / 2;
	int count = 0;
	cout << "Среднее значение: " << average << endl;

	auto isFind{ find(list, list+N, average) };
	if (isFind != list+N)
		cout << "Индексы: ";

	if (isSorted){
		for (int i = 0; i < N; i++) {
			if (list[i] > average) break;
			if (list[i] == average) {
				count++;
				cout << i << " ";
			}
		}
	}
	else{
		for (int i = 0; i < N; i++) {
			if (list[i] == average) {
				count++;
				cout << i << " ";
			}
		}
	}
	(count == 0 ? cout << "таких элементов нет" : cout << "\nКоличество: " << count);
}


void findSmallerThenA(int a, int list[], int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] < a) { count++; }
		else { break; }
	}
	cout << "Количество: " << count << "\n";
}


void findBiggerThenB(int b, int list[], int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] > b) { count++; }
		else { continue; }
	}
	cout << "Количество: " << count << "\n";
}


int BinSearch(int list[], int N, int num)
{
	int l = 0;        // нижняя граница
	int u = N - 1;    // верхняя граница

	while (l <= u) {
		int m = (l + u) / 2;
		if (list[m] == num) return m;
		if (list[m] < num) l = m + 1;
		if (list[m] > num) u = m - 1;
	}
	return -1;
}


void idz(int list[], int N, int num) {
	int changeList[100]{};
	for (int i = 0; i < N; i++) {
		changeList[i] = list[i];
	}
	cout << "\nДо всех изменений\n";
	showArray(list, N);

	for (int i = 0; i < N; i += 2) {
		changeList[i] = list[i] - num;
	}
	cout << "\n\nПосле уменьшения на выбранное число:\n";
	showArray(changeList, N);

	cout << "\n\nКаждый четный элемент умножается на случайную величину в диапазоне от 1 до 9\n";
	srand(time(0));
	int rd = 0;
	for (int i = 0; i < N; i += 2) {
		changeList[i] = list[i] * (1 + rand() % 9);
	}
	showArray(changeList, N);

	int cEven = 0, cOdd = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			if (list[i] % 2 == 0) { cEven++; }
		}
		else {
			if (list[i] % 2 == 1) { cOdd++; }
		}
	}
	cout << "\n\nКоличество четных на четных местах: " << cEven << "\nКоличество нечетных на нечетных местах: " << cOdd << "\n\n";
	
	int c = 0;
	cout << "Количество элементов, которые нацело делятся\n";
	for (int i = 1; i < 10; i++) {
		c = 0;
		for (int j = 0; j < N; j++) {
			if (list[j] % i == 0) c++;
		}
		cout << "на " << i << ": " << c << endl;
	}
}


int main()
{
	setlocale(0, "");
	auto begin = chrono::high_resolution_clock::now();
	auto end = chrono::high_resolution_clock::now();
	const int N = 100;
	int max = -101, min = 101;
	int sortMax = 0, sortMin = 0;
	int list[N]{};
	int sortList[N]{};

	while (true) {
		int action;
		cout << "\n\n";

		menu();
		cout << "\nВыберите действие: ";
		cin >> action;
		if (action == 0) { break; }
		cout << "\n";
		system("cls");

		switch (action)
		{
		case 1:
		{
			srand(time(0));
			for (int i = 0; i < N; i++) {
				list[i] = -99 + rand() % 199;
				sortList[i] = list[i];
			}

			cout << "Массив со случайными значениями: \n";
			showArray(list, N);
			break;
		}
		case 2:
		{
			cout << "\nВыберите сортировку: 1) Bubble sort 2) Shaker sort 3) Comb sort 4) Insert sort 5) Quick sort\n";
			int a; cin >> a;
			begin = chrono::high_resolution_clock::now();
			switch (a)
			{
			case 1:
				bubbleSort(sortList, N);
				break;
			case 2:
				shakerSort(sortList, N);
				break;
			case 3:
				combSort(sortList, N);
				break;
			case 4:
				insertSort(sortList, N);
				break;
			case 5:
				quickSort(sortList, N);
				break;
			default:
				break;
			}
			end = chrono::high_resolution_clock::now();
			cout << "Отсортированный массив: ";
			showArray(sortList, N);
			cout << "\nВремя: " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) << "us\n\n";
			break;
		}
		case 3:
		{
			cout << "В отсортированном массиве:\n";
			begin = chrono::high_resolution_clock::now();
			sortMax = sortList[N - 1];
			sortMin = sortList[0];
			end = chrono::high_resolution_clock::now();
			cout << "Максимальный элемент: " << sortMax << "\nМинимальный элемент: " << sortMin << "\t";
			cout << "Время: " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) << "us\n\n";

			
			cout << "\n\nВ неотсортированном массиве : \n";
			begin = chrono::high_resolution_clock::now();
			findMinMax(&max, &min, list, N);
			end = chrono::high_resolution_clock::now();
			cout << "\tВремя: " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) << "us\n\n";
			break;
		}
		case 4:
		{
			cout << "В отсортированном массиве\n";
			begin = chrono::high_resolution_clock::now();
			findAverage(true, sortMax, sortMin, sortList, N);
			end = chrono::high_resolution_clock::now();
			cout << "\tВремя: " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) << "us\n\n";

			cout << "В неотсортированном массиве\n";
			begin = chrono::high_resolution_clock::now();
			findAverage(false, max, min, list, N);
			end = chrono::high_resolution_clock::now();
			cout << "\tВремя: " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) << "us\n\n";
			break;
		}
		case 5:
		{
			cout << "Введите число а[-99;99]: ";
			int a;
			cin >> a;
			findSmallerThenA(a, sortList, N);
			break;
		}
		case 6:
		{
			cout << "Введите число b[-99;99]: ";
			int b;
			cin >> b;
			findBiggerThenB(b, list, N);
			break;
		}
		case 7:
		{
	
			cout << "Введите число, которое нужно найти: ";
			int num;
			cin >> num;

			begin = chrono::high_resolution_clock::now();
			int binIndex = BinSearch(sortList, N, num);
			end = chrono::high_resolution_clock::now();

			cout << "\nВ отсортированном массиве\n";
			if (binIndex != -1) cout << "Индекс элемента " << num << " равен: " << binIndex;
			else cout << "Такого элемента в массиве нет";
			cout << "\tВремя: " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) << "us\n\n";


			begin = chrono::high_resolution_clock::now();
			int index;
			bool f = false;
			for (int i = 0; i < N; i++) {
				if (list[i] == num) {
					index = i;
					f = true;
				}
			}
			end = chrono::high_resolution_clock::now();
			cout << "\nВ неотсортированном массиве\n";
			if (f == true) { cout << "Индекс элемента " << num << " равен: " << index; }
			else { cout << "Такого элемента в массиве нет"; }
			cout << "\tВремя: " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) << "us\n\n";

			break;
		}
		case 8:
		{
			cout << "Введите индексы элементов, которые нужно поменять местами: ";
			int index1, index2;
			cin >> index1 >> index2;
			cout << "\nДо: ";
			showArray(list, N);
			begin = chrono::high_resolution_clock::now();
			swap(list[index1], list[index2]);
			end = chrono::high_resolution_clock::now();

			cout << "\n\nПосле: ";
			showArray(list, N);
			cout << "\nВремя: " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) << "us\n\n";

			break;
		}
		case 9:
		{
			cout << "\nOтсортированный массив:\n";
			showArray(sortList, N);
			cout << "\n\nНеотсортированный массив:\n";
			showArray(list, N);
			break;
		}
		case 10:
		{
			cout << "\nВведите число, на которое надо уменьшить каждый четный элемент: ";
			int num;
			cin >> num;
			idz(list, N, num);
			break;
		}
		default:
			cout << "\nНет такого варианта";
			break;
		}
		cout << "\n\n";
		system("pause");
		system("cls");
	}
}