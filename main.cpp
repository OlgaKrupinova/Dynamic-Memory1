 #include <iostream>
#include <cstdlib>
#include <ctime>



//Вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

//функция заполнения массива сл числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void arr_app(T*& arr, int& length, int num) {
	//шаг 0 проверка на кол-во элементов для увеличения размера массива
	if (num <= 0)
		return;

	//шаг 1 создание нового дин массива нужного размера
	T* tmp = new T[length + num]{};

	//шаг 2 копирование значений старого массива в элементы нового массива
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];

	//шаг 3 удаление старого массива
	delete[] arr;

	//шаг 4 перенаправление указателя на новый массив
	arr = tmp;  

	//шаг 5 увеличение переменной отвечающей за размер массива
	length += num;

	
}


template <typename T>
void arr_opp(T*& arr, int& length, int num) {
	if (length <= 0)
		return;
	if (num >= length) {
		delete[] arr;
		arr = nullptr;
		return;
	}
	T* tmp = new T[length - num];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
	length -= num;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;


	//Выделение динамической памяти под переменные
	int* pointer = new int;//выделение участка динамической памяти типа инт и
	//сохранение и сохранение ее адреса в указателе
	*pointer = 7;//запись в выделенную ранее динамическую память числа 7

	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;

	delete pointer;//освобождение памяти на которую направлен указатель

	pointer = new int;//перенаправление указателя на новую область динамической памяти
	*pointer = 15;

	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;

	//Динамические массивы
	std::cout << "введите размер массива ->  ";
	int dsize;
	std::cin >> dsize;
	int* darr = new int[dsize];

	std::cout << "Ввод данных в массив:\n";
	for (int i = 0; i < dsize; i++) {
		std::cout << "Введите " << i + 1 << "-е число -> ";
		std::cin >> darr[i];
	}
	std::cout << "Итоговый массив:\n";
	print_arr(darr, dsize);

	delete[] darr;
	
	//Двумерные динамические массивы
	int rows = 5, cols = 6;
	//int* mx = new int[rows][cols];//НЕ РАБОТАЕТ

	//Выделение памяти   
	int** mx = new int* [rows];
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];

	//Освобождение памяти
	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[] mx;

	//Задача 1 увеличение размера массива
	std::cout << "Задача 1. \nВведите размер массива -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 21);
	std::cout << "Изначальный массив: \n";
	print_arr(arr1, size1);

	std::cout << "Введите кол-во новых элементов -> ";
	std::cin >> n;

	arr_app(arr1, size1, n);

	std::cout << "Итоговый массив: \n";
	print_arr(arr1, size1);



	//Задача 1 уменьшение размера массива
	std::cout << "Задача 1. \nВведите размер массива -> ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 10, 21);
	std::cout << "Изначальный массив: \n";
	print_arr(arr2, size2);

	std::cout << "Введите кол-во элементов для удаления -> ";
	std::cin >> n;

	arr_opp(arr2, size2, n);

	std::cout << "Итоговый массив: \n";
	print_arr(arr2, size2);




	return 0;
}