#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int rowCol, mineNum, x, y;
char displayGame[20][20];
char mainGame[20][20];
void mineSweeper();
void mineCounter();
void showGame(char game[20][20]);
void playGame();
void enterRow();
void enterCol();
int checkGame();
void environsZero();
void playAgain();
void main()
{
	system("color 16");
	cout << "\n";
	cout << "\t\t\t\t\t\tWelcome To MineSweeper Game" << endl << endl;
	cout << "\t\t\t\tHow Many Row And Column You Want To Have Your Square : ";
	cin >> rowCol;
	cout << "\n";
	cout << "\t\t\t\tHow Many Mines You Want To Be In The Game (1 - " << (rowCol*rowCol - 1)<<") : ";
	cin >> mineNum;
	mineSweeper();
	showGame(displayGame);
	playGame();
	playAgain();
}
void mineSweeper()
{
	system("color 16");
	system("cls");
	srand(rowCol);
	for (int row = 0; row < rowCol; row++) 
		for (int col = 0; col < rowCol; col++) 
		{
			displayGame[row][col] = '-';
			mainGame[row][col] = '0';
		}
	for (int i = 0; i < mineNum; i++) 
	{
		int row = (rand() % rowCol);
		int col = (rand() % rowCol);
		while (mainGame[row][col] == '@') 
		{
			row = (rand() % rowCol);
			col = (rand() % rowCol);
		}
		mainGame[row][col] = '@';
	}
	mineCounter();
}
void mineCounter()
{
	system("color 16");
	for (int row = 0; row < rowCol; row++)
		for (int col = 0; col < rowCol; col++)
			if (mainGame[row][col] == '@')
				for (int x = row - 1; x <= row + 1; x++)
					for (int y = col - 1; y <= col + 1; y++)
						if (x >= 0 && x <= (rowCol - 1))
							if (y >= 0 && y <= (rowCol - 1))
								if (mainGame[x][y] != '@')
									mainGame[x][y] += 1;
}
void showGame(char game[20][20])
{
	system("color 16");
	int j = 1;
	cout << "\t\t\t\t\t  ";
	for (int i = 1; i <= rowCol; i++)
	{
		if (i < 10)
			cout << "  " << i;
		else
			cout << " " << i;
	}
	cout << endl;
	cout << "\t\t\t\t\t   ";
	for (int i = 1; i <= rowCol; i++)
	{
		if (i < 10)
			cout << "---";
		else
			cout << "---";
	}
	cout << endl;
	for (int row = 0; row < rowCol; row++)
	{
		if (j < 10)
			cout << "\t\t\t\t\t " << j << " ";
		else
			cout << "\t\t\t\t\t" << j << " ";
		for (int col = 0; col < rowCol; col++)
			cout << "|" << game[row][col] << "|";
		cout << endl;
		j++;
	}
	cout << "\t\t\t\t\t   ";
	for (int j = 0; j < rowCol; j++)
		cout << "---";
	cout << endl;
}
void playGame()
{
	system("color 16");
	int counter;
	char operation;
	for (int i = 0; i <= (rowCol*rowCol*rowCol); i++)
	{
		enterRow();
		enterCol();
		while (displayGame[x - 1][y - 1] == mainGame[x - 1][y - 1])
		{
			cout << "You Allready Chose This Place Before!" << endl;
			enterRow();
			enterCol();
		}
		cout << "\n\t\t\t\t\t1)Open  2)Flag  3)Cancel : ";
		cin >> operation;
		switch (operation)
		{
		case '1':
			if (mainGame[x - 1][y - 1] == '@')
			{
				system("cls");
				showGame(mainGame);
				cout << "\n\t\t\t\t\tOpps! You stepped on a mine!" << endl << endl;
				cout << "\t\t\t\t\t\tGame Over!" << endl << endl;
				return;
			}
			else
			{
				system("cls");
				displayGame[x - 1][y - 1] = mainGame[x - 1][y - 1];
				environsZero();
				showGame(displayGame);
				counter = checkGame();

				if (counter == ((rowCol*rowCol) - mineNum))
				{
					system("cls");
					showGame(mainGame);
					cout << "\n\t\t\t\t\tCongrats! You've cleared all the mines!" << endl;
					return;
				}
			}
			break;
		case '2':
			displayGame[x - 1][y - 1] = 'F';
			system("cls");
			showGame(displayGame);
			break;
		case '3':
			system("cls");
			showGame(displayGame);
			break;
		default:
			system("cls");
			showGame(displayGame);
			break;
		}

	}
}
void enterRow()
{
	system("color 16");
	cout << "\t\t\t\t\tPlease Enter Row : ";
	cin >> x;
	while (x<1 || x>rowCol)
	{
		cout << "\t\t\t\t\tError!!!" << endl;
		cout << "\t\t\t\t\tPlease Enter Row (1 - " << rowCol << ") : ";
		cin >> x;
	}
}
void enterCol()
{
	system("color 16");
	cout << "\t\t\t\t\tPlease Enter Column : ";
	cin >> y;
	while (y<1 || y>rowCol)
	{
		cout << "\t\t\t\t\tError!!!" << endl;
		cout << "\t\t\t\t\tPlease Enter Column (1 - " << rowCol << ") : ";
		cin >> y;
	}
}
int checkGame()
{
	system("color 16");
	int counter = 0;
	for (int i = 0; i < rowCol; i++)
		for (int j = 0; j < rowCol; j++)
			if (displayGame[i][j] == mainGame[i][j])
				counter += 1;
	return counter;
}
void environsZero()
{
	system("color 16");
	if (mainGame[x - 1][y - 1] == '0')
		for (int i = x - 2; i < x + 1; i++)
			for (int j = y - 2; j < y + 1; j++)
				if (i >= 0 && i < rowCol)
					if (j >= 0 && j < rowCol) 
					{
						displayGame[i][j] = mainGame[i][j];
						if (mainGame[i][j] == '0')
							for (int i2 = x - 1; i2 < x + 2; i2++)
								for (int j2 = y - 1; j2 < y + 2; j2++)
									if (i2 > 0 && i2 < rowCol)
										if (j2 > 0 && j2 < rowCol)
											if (mainGame[i2][j2] != '@')
												displayGame[i2][j2] = mainGame[i2][j2];
					}
}
void playAgain()
{
	system("color 16");
	char again;
	cout << "\n\t\t\t\t\t1)Restart  2)Exit : ";
	cin >> again;
	switch (again)
	{
	case '1':
		system("cls");
		main();
		break;
	case '2':
		break;
	default:
		cout << "Invalid Input!" << endl;
		playAgain();
		break;
	}

}