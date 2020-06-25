#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include<string>
using namespace std;

int main()
{
	setlocale(0, "ru");

	srand(time(NULL));
	//для проверки лучше брать большое количество матриц маленького размера(20 матрииц размера 2х2)
	int k;
	cout << "Введите количество матриц ";
	cin >> k;
	int n;
	cout << "Введите размер матриц ";
	cin >> n;
	for (int i = 0; i < k; i++)
	{
		ofstream file1;
		file1.open("File1.txt", ofstream::app);
		if (!file1.is_open()) cout << "Error";
		ofstream file2;
		file2.open("File2.txt", ofstream::app);
		if (!file2.is_open()) cout << "Error";

		int** arr = new int* [n];
		for (int j = 0; j < n; j++)
		{
			arr[j] = new int[n];
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				arr[j][k] = rand() % 20 + 1;
				//cout << arr[j][k] << "\t";
			}
			//cout << endl;
		}
		int num = n * n-n;
		int it = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{

				if (arr[j][k] == arr[k][j])
				{
					it++;
					if (j == k)
					{
						it--;
					}
				}
			}
		}
		if (it == num)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					file1 << arr[j][k] << " ";
				}
				file1 << endl;
			}
			file1 << endl;
			file1.close();
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					file2 << arr[j][k] << " ";
				}
				file2 << endl;
			}
			file2 << endl;
			file2.close();
		}

		for (int j = 0; j < n; j++)
			delete[] arr[j];
		delete[]arr;
	}


	ifstream fil1;
	fil1.open("File1.txt");
	if (!fil1.is_open()) cout << "Error";
	else
	{
		cout << "Матрицы из первого файла " << endl;
		string s;
		while (!fil1.eof())
		{
			string s = "";
			getline(fil1, s);
			cout << s << endl;
		}
		fil1.close();
	}
	cout << "====================================\n\n";
	ifstream fil2;
	fil2.open("File2.txt");
	if (!fil2.is_open()) cout << "Error";
	else
	{
		cout << "Матрицы из второго файла " << endl;
		string s;
		while (!fil2.eof())
		{
			string s = "";
			getline(fil2, s);
			cout << s << endl;
		}
		fil2.close();
	}
	return 0;
}
