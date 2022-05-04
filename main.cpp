#include <iostream>
#include <stack>
#include <array>
#include <ctime>
using namespace std;
void increment(int*);
void incrementStackVariable();
void incrementHeapVariable();
void writeArray(int* arr, int n);
void readArray(int* arr, int n);
void sort(int*, int);
void sortStackArray();
void sortHeapArray();
int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	while (true)
	{
		cout << endl << endl << endl;
		cout << "Лабораторная работа № 4. Введите какое задание хотели бы выполнить \n";
		cout << "2. 	Задание 2 \n";
		cout << "3. 	Задание 3 \n";
		cout << "7. 	Задание 7 \n";
		cout << "8. 	Задание 8 \n";
		cout << "6.	Выход \n";
		cin >> choice;
		switch (choice)
		{

		case 2:
			system("cls");
			incrementStackVariable();
			break;
		case 3:
			system("cls");
			incrementHeapVariable();
			break;
		case 7:
			system("cls");
			sortStackArray();
			break;
		case 8:
			system("cls");
			sortHeapArray();
			break;
		case 6:
			system("cls");
			cout << "Выход из программы. \n \n Спасибо, что воспользовались моим приложением!! \n";
			return 0;
		}
	} 
}

// Задание 1
void increment(int* n)
{
	cout << n << "\t" << *n << "\t";
	if (!n) n = new int;
	*n += 1;
	cout << n << "\t" << *n << "\t";
}

//Задание 2
void incrementStackVariable() 
{
	int x;
	stack <int> stack1;
	cin >> x;
	stack1.push(x);
	int* xp = &stack1.top();
	cout << xp << "\t" << *xp << "\t";
	increment(xp);
}

//Задание 3
void incrementHeapVariable()
{
	int* a = new int;
	cin >> *a;
	cout << a << "\t" << *a  << endl;
	increment(a);
	cout << a << "\t" << *a << endl;
	delete a;
}

//Задание  4
void writeArray(int* arr, int n)
{ 
	for (int i = 0; i <= n-1; i++)
	{
		cout << arr[i] << " ";
	}
}

//Задание 5
void readArray(int* arr, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		cin >> arr[i];
	}
}

//Задание 6
void sort(int* arr, int n)
{
	for (int i = 1; i <= (n-1); i++)
	{
		static int x;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j])
			{
				x = arr[i];
				arr[i] = arr[j];
				arr[j] = x;
				i--;
			}
		}
	}
}
//void generate_content(int* numbers, int N)
//{
//	srand(time(NULL));
//	for (int i = 0; i <= (N - 1); i++)
//	{
//		numbers[i] = rand();
//	}
//}

//Задание 7
void sortStackArray()
{
	const int N = 8;
	int arr[N];
	cout << N << endl;
	readArray(arr, N);
	writeArray(arr, N);
	cout << endl;
	sort(arr, N);
	writeArray(arr, N);
}

void sortHeapArray()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	readArray(arr, N);
	cout << endl << N << endl;
	writeArray(arr, N);
	cout << endl;
	sort(arr, N);
	writeArray(arr, N);
	delete[] arr;
}