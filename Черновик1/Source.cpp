#include <iostream>
#include <random>
#include <string.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
random_device Rand;

void create_map(char mas_player[10][10], char mas_enemy[10][10], char mas_computer[10][10], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mas_player[i][j] = '-';
			mas_enemy[i][j] = '-';
			mas_computer[i][j] = '-';
		}
	}
}

void print_map(char mas_player[10][10], char mas_enemy[10][10], char mas_computer[10][10], int size)
{
	cout << "+-+-+- Ваша карта -+-+-+" << endl;
	for (int i = 0; i < size; i++) //Вывод карты
	{
		for (int j = 0; j < size; j++)
		{
			cout << mas_player[j][i] << ' ';
		}
		cout << endl;
	}
	cout << endl << "+-+-+- Карта попаданий -+-+-+" << endl;
	for (int i = 0; i < size; i++) //Вывод карты врага 
	{
		for (int j = 0; j < size; j++)
		{
			cout << mas_enemy[j][i] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	cout << "Лодки врага(подсказка)" << endl;
	for (int i = 0; i < size; i++) //Вывод карты врага 
	{
		for (int j = 0; j < size; j++)
		{
			cout << mas_computer[j][i] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	const int map_size = 10;
	int x = 0, y = 0;
	int x_comp = 0, y_comp = 0;

	char mas_player[map_size][map_size] = {};
	char mas_computer[map_size][map_size] = {};
	char mas_enemy[map_size][map_size] = {};

	bool step = false;

	//заполнение карты
	create_map(mas_player, mas_enemy, mas_computer, map_size);

	//Ввод лодок 5-кол-во лодок
	for (int i = 0; i < 2; i++)
	{
		/*расстановка лодок игрока*/
		cout << "Введите координаты лодки: " << endl;
		cin >> x;
		cin >> y;
		mas_player[x][y] = '#';

		/*расстановка лодок компютера*/
		x_comp = Rand() % 10;
		y_comp = Rand() % 10;
		mas_computer[x_comp][y_comp] = '#';
	}

	//вывод карты
	print_map(mas_player, mas_enemy, mas_computer, map_size);

	while (true)
	{
		if (step == false) //Стрельба по цели player
		{
			cout << "Введите координаты цели: ";
			cin >> x >> y;
			if (mas_computer[x][y] == '#')
			{
				cout << "Есть пробитие!" << endl;
				mas_computer[x][y] = 'x';
				mas_enemy[x][y] = 'x';
				system("cls"); //сброс карты
				print_map(mas_player, mas_enemy, mas_computer, map_size);
			}
			else
			{
				system("cls"); //сброс карты 
				cout << "Мимо!" << endl;
				mas_enemy[x][y] = 'P';
				print_map(mas_player, mas_enemy, mas_computer, map_size);
			}
			step = true;
		}

		if (step == true) //Стрельба по цели computer 
		{
			x_comp = Rand() % 10;
			y_comp = Rand() % 10;
			if (mas_player[x_comp][y_comp] == '#')
			{
				mas_player[x_comp][y_comp] = 'x';
			}
			else
			{
				mas_player[x_comp][y_comp] = 'E';
			}
			step = false;
		}
	}
	system("pause");
	return 0;
}