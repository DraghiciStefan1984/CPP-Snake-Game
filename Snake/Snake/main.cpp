#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

//global variables
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction direction;

void Settings()
{
	gameOver = false;
	direction = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
}

void Visual()
{
	system("cls");
	for (int i = 0; i < width; i++) cout << '#';
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1) cout << '#';
			else cout << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) cout << '#';
	cout << endl;
}

void Logic()
{

}

void Input()
{

}

int main()
{
	Settings();
	while (!gameOver)
	{
		Visual();
		Input();
		Logic();
	}
	return EXIT_SUCCESS;
}