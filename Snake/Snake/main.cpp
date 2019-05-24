#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

//global variables
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, tailNum;
int tailX[50], tailY[50];
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
			if (j == 0) cout << '#';
			if (i == y && j == x) cout << 'o';
			else if (i == fruitY && j == fruitX) cout << '*';
			else
			{
				bool printTail = false;
				for (int k = 0; k < tailNum; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << 'o';
						printTail = true;
					}
				}
				if(!printTail) cout << ' ';
			}
			if (j == width - 1) cout << '#';
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) cout << '#';
	cout << endl;
	cout << "Score: " << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			direction = LEFT;
			break;
		case 'd':
			direction = RIGHT;
			break;
		case 'w':
			direction = UP;
			break;
		case 's':
			direction = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	int previousX = tailX[0];
	int previousY = tailY[0];
	int previous2X, previous2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < tailNum; i++)
	{
		previous2X = tailX[i];
		previous2Y = tailY[i];
		tailX[i] = previousX;
		tailY[i] = previousY;
		previousX = previous2X;
		previousY = previous2Y;
	}

	switch (direction)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x >= width) x = 0;
	if (x < 0) x = width - 1;
	if (y >= height) y = 0;
	if (y < 0) y = height - 1;

	if(x==fruitX && y==fruitY)
	{
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}



int main()
{
	Settings();
	while (!gameOver)
	{
		Visual();
		Input();
		Logic();
		Sleep(100);
	}
	return EXIT_SUCCESS;
}