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

	if (direction == "�����") {

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
	else if (direction == "������") {

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


	cout << "��������� ������:" << endl;
	printArray(arr);
	cout << endl;

	int shift;
	string direction;
	cout << "������� ����� �������: ";
	cin >> shift;
	cout << "������� ��������� ������ (�����/������): ";
	cin >> direction;
	cout << endl;

	shiftArray(arr, shift, direction);

	cout << "�������� ������:" << endl;
	printArray(arr);

	return 0;
}

/*������� 3. �������� ���������� ������.��������� ���
���������� ������� � �������� �� �����. ������������
�������� ���������� ������� � ��������� (�����, ������, �����, ����).
��������� ����� ������� � �������� �� ����� ���������� ���������. ����� �����������.
��������, ���� �� ����� ��������� ������
1 2 0 4 5 3
4 5 3 9 0 1
� ������������ ������ ����� �� 2 ������� ������, �� �� �������
5 3 1 2 0 4
0 1 4 5 3 9.*/