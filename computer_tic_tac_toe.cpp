// Tic_Tac_Toe, by Ian Lundberg

// Include the libraries
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>


// Use the standard namespace
using namespace std;

// Declare global variables
char Board[9];

// Declare functions
void showBoard();
bool moveIsValid(int m);
int whoWon();    // Returns 0 if no one has won, 1 if player 1 has won, and 2 if player 2 has won

void main()
{

  // Changes the title of the window
	SetConsoleTitle(L"Tic Tac Toe");

	// Declare local variables
	string Player_1_Name;
	string Player_2_Name;
	int Whose_Turn = 1;    // 1 means it's player 1's turn, 2 means it's player 2's turn
	int Move = -1;    // Stores where the player wants to move
	int Total_Moves = 0;
	int Computer_Limiter = 1;

	// Assign values to the playing board
	Board[0] = '0';
	Board[1] = '1';
	Board[2] = '2';
	Board[3] = '3';
	Board[4] = '4';
	Board[5] = '5';
	Board[6] = '6';
	Board[7] = '7';
	Board[8] = '8';

	// Get player names
	cout << "Player 1: Please enter your name." << endl;
	cin >> Player_1_Name;

	while (whoWon() == 0 && Total_Moves < 9)
	{
		// Do this until the player chooses a valid move
		do
		{
			while (!Move < 9)
			{

				// Show the board
				system("cls");
				showBoard();

				// Tell which player to move
				if (Whose_Turn == 1)
				{
					// Tells the player what the computer picked
					if (Move != -1)
					{
						cout << "The computer picked " << Move << endl << endl;
					}
					
					// Tells the player it's their turn
					cout << Player_1_Name << ": It's your turn." << endl;


					// Get player 1's move
					cout << "Enter the number of the spot where you'd like to move." << endl;
					cin >> Move;
				}
				else
				{
					
					// Seed the random number
					srand(time(NULL));

					// Gets the random number that the computer is going to move to
					Move = rand() % 9;
					cout << "The computer is trying to move." << endl;
				}
				if (Move < 9)
				{
					break;
				}
			}
		} while (moveIsValid(Move) != true);

		// Add 1 to Total_Moves
		Total_Moves++;

		// Change whose turn it is
		switch (Whose_Turn)
		{
		case(1):
			{
				Board[Move] = 'x';
				Whose_Turn = 2;
				break;
			}
		case(2):
			{
				Board[Move] = 'o';
				Whose_Turn = 1;
			}
		}
	}
	// Show the board
	system("cls");
	showBoard();
	if (whoWon() == 1)
	{
		cout << Player_1_Name << " has won the game!" << endl;
	}
	else if (whoWon() == 2)
	{
		cout << "The computer has won the game!" << endl;
	}
	else
	{
		cout << "It's a tie game!" << endl;
	}

	system("PAUSE");
}

int whoWon()
{
	if (Board[0] == Board[1] && Board[1] == Board[2])
	{
		if (Board[0] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (Board[3] == Board[4] && Board[4] == Board[5])
	{
		if (Board[3] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (Board[6] == Board[7] && Board[7] == Board[8])
	{
		if (Board[6] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (Board[0] == Board[3] && Board[3] == Board[6])
	{
		if (Board[0] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (Board[1] == Board[4] && Board[4] == Board[7])
	{
		if (Board[1] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (Board[2] == Board[5] && Board[5] == Board[8])
	{
		if (Board[2] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (Board[0] == Board[4] && Board[4] == Board[8])
	{
		if (Board[0] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (Board[2] == Board[4] && Board[4] == Board[6])
	{
		if (Board[2] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	return 0;
}

bool moveIsValid(int m)
{
	if(Board[m] != 'x' && Board[m] != 'o')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void showBoard()
{
	cout << endl << Board[0] << " | " << Board[1] << " | " << Board[2] << endl;
	cout << "--+---+--" << endl;
	cout << Board[3] << " | " << Board[4] << " | " << Board[5] << endl;
	cout << "--+---+--" << endl;
	cout << Board[6] << " | " << Board[7] << " | " << Board[8] << endl << endl;
}