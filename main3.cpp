#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int rows = 2;
const int cols = 6;

void fillArray(int arr[rows][cols]) {

	srand(time(0));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			arr[i][j] = rand() % 10;
		}
	}
}

void printArray(int arr[rows][cols]) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void shiftArray(int arr[rows][cols], int shift, string direction) {

	int temp[cols];

	if (direction == "влево") {

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < shift; j++) {
				temp[j] = arr[i][j];
			}

			for (int j = 0; j < cols - shift; j++) {
				arr[i][j] = arr[i][j + shift];
			}

			for (int j = 0; j < shift; j++) {
				arr[i][cols - shift + j] = temp[j];
			}
		}
	}
	else if (direction == "вправо") {

		for (int i = 0; i < rows; i++) {
			for (int j = cols - shift; j < cols; j++) {
				temp[j - (cols - shift)] = arr[i][j];
			}

			for (int j = cols - 1; j >= shift; j--) {
				arr[i][j] = arr[i][j - shift];
			}

			for (int j = 0; j < shift; j++) {
				arr[i][j] = temp[j];

			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");

	int arr[rows][cols];
	fillArray(arr);


	cout << "Начальный массив:" << endl;
	printArray(arr);
	cout << endl;

	int shift;
	string direction;
	cout << "Введите число сдвигов: ";
	cin >> shift;
	cout << "Введите положение сдвига (влево/вправо): ";
	cin >> direction;
	cout << endl;

	shiftArray(arr, shift, direction);

	cout << "Конечный массив:" << endl;
	printArray(arr);

	return 0;
}

/*Задание 3. Создайте двухмерный массив.Заполните его
случайными числами и покажите на экран. Пользователь
выбирает количество сдвигов и положение (влево, вправо, вверх, вниз).
Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический.
Например, если мы имеем следующий массив
1 2 0 4 5 3
4 5 3 9 0 1
и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
5 3 1 2 0 4
0 1 4 5 3 9.*/