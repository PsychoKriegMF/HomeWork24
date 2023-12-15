#include <iostream>
#include <cstdlib>
#include <ctime>


void fill_arr(int arr[], int length, int min, int max);

template <typename T>
void print_arr(T arr[], int length);

template <typename T>
void resize_arr(T*& arr, int length, int new_size);

int main() {
	system("chcp 1251>null");

	std::cout << "\tЗадача 1.\n";
	int dsize, dsize2;
	std::cout << "Введите размер первого массива -> ";
	std::cin >> dsize;
	std::cout << "Введите размер второго массива -> ";
	std::cin >> dsize2;

	int* arrA = new int[dsize];
	int* arrB = new int[dsize2];

	fill_arr(arrA, dsize, 10, 50);
	fill_arr(arrB, dsize2, 50, 100);

	std::cout << "Первый массив: ";
	print_arr(arrA, dsize);
	std::cout << "Второй массив: ";
	print_arr(arrB, dsize2);

	int* arrC = new int[dsize + dsize2];
	for (int i = 0; i < dsize; i++)
		arrC[i] = arrA[i];
	for (int i = dsize; i < dsize + dsize2; i++)
		arrC[i] = arrB[i - dsize];

	std::cout << "Третий массив: ";
	print_arr(arrC, dsize + dsize2);

	delete[] arrA;
	delete[] arrB;

	std::cout << "\n\tЗадача 2.\n";
	int dsize3;
	std::cout << "Введите размер массива -> ";
	std::cin >> dsize3;
	int* arr3 = new int[dsize3];
	fill_arr(arr3, dsize3, 25,75);
	std::cout << "Изначальный массив заполненный случайными числами: ";
	print_arr(arr3, dsize3);
	std::cout << "Введите на сколько увеличить размер массива -> ";
	int n;
	std::cin >> n;
	resize_arr(arr3,dsize3, n);
	if (n > 0) {
		std::cout << "Массив увеличенный на " << n <<'\n';
		dsize3 += n;
		print_arr(arr3, dsize3);
	}
	else
		std::cout << "Ошибка ввода!" << std::endl;



	return 0;
}

void fill_arr(int arr[], const int length, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b } \n";
}

template <typename T>
void resize_arr(T*& arr, int length, int new_size) {
	if (new_size <= 0)
		return;
	T* tmp = new T[length + new_size]{};
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}