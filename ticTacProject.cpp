#include <bits/stdc++.h>
#include <limits>
#define f(n) for (int i = 0; i < n; i++)

const int Rows = 3, Cols = 3;
char arr[Rows][Cols] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

using namespace std;

// print board
void printBoard()
{
    cout << " _______ _______ _______\n";
    f(3)
    {
        cout << "|       |       |       |\n";
        cout << "|   " << arr[i][0] << "   |   " << arr[i][1] << "   |   " << arr[i][2] << "   |\n";
        cout << "|_______|_______|_______|\n";
    }
    cout << endl;
}
// check if the place outside the board
bool checkInputOutSide(short row, short col)
{
    if (row < 1 || row > 3 || col < 1 || col > 3)
    {
        cout << "You have to enter the place inside the Board Bro!, So enter it again" << endl;
        return true;
    }
    return false;
}
// check if the place is not empty in the board
bool checkNoTEmptyPlace(short row, short col)
{
    if (arr[row - 1][col - 1] == 'X' || arr[row - 1][col - 1] == 'O')
    {
        cout << "The cell is not empty Bro!, Try again to play !" << endl;
        return true;
    }
    return false;
}
// Drawing the Board after each play
void drawBoard(char c, short row, short col)
{
    arr[row][col] = toupper(c);
    cout << "\nThe Board now is : " << endl;
    printBoard();
    cout << endl;
}
// Checking the winner each play
char checkWin(char arr[3][3])
{
    short noOfXs, noOfOs;

    // loop starting for each row
    f(3)
    {
        // row starting
        noOfOs = 0, noOfXs = 0;
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == toupper('o'))
                noOfOs++;
            else if (arr[i][j] == toupper('x'))
                noOfXs++;
        }
        if (noOfOs == 3)
            return 'o';
        else if (noOfXs == 3)
            return 'x';
        // row ending
    }
    // loop end for each row
    // loop starting for each col
    f(3)
    {
        // col starting
        noOfOs = 0, noOfXs = 0;
        for (int j = 0; j < 3; j++)
        {
            if (arr[j][i] == toupper('o'))
                noOfOs++;
            else if (arr[j][i] == toupper('x'))
                noOfXs++;
        }
        if (noOfOs == 3)
            return 'o';
        else if (noOfXs == 3)
            return 'x';
        // col ending
    }
    // loop end for each col
    // loop starting for diagonal
    noOfOs = 0, noOfXs = 0;
    f(3)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                if (arr[i][j] == toupper('o'))
                    noOfOs++;
                else if (arr[i][j] == toupper('x'))
                    noOfXs++;
            }
        }
        if (noOfOs == 3)
            return 'o';
        else if (noOfXs == 3)
            return 'x';
    }

    // loop end for each diagonal
    // second diagonal

    noOfOs = 0, noOfXs = 0;

    if (arr[0][2] == toupper('o'))
        noOfOs++;
    else if (arr[0][2] == toupper('x'))
        noOfXs++;

    if (arr[2][0] == toupper('o'))
        noOfOs++;
    else if (arr[2][0] == toupper('x'))
        noOfXs++;

    if (arr[1][1] == toupper('o'))
        noOfOs++;
    else if (arr[1][1] == toupper('x'))
        noOfXs++;

    if (noOfOs == 3)
        return 'o';
    else if (noOfXs == 3)
        return 'x';

    return '0';
}
void printPlayer(int playerNum)
{
    cout << " ===================================\n";
    cout << "|                                   |\n";
    cout << "|     The Winner is Player " << playerNum << "        |\n";
    cout << "|                                   |\n";
    cout << " ===================================\n";
}
int main()
{
    cout << "_______________________________\n\n";
    cout << "    Tic-Tac-Toe: X-O Game    \n";
    cout << "_______________________________" << endl;
    short row, col, noOfCells = 0;
    char c, player = '2', player1, player2;
    cout << "\nPlayer 1, Choose your weapon X or O ?" << endl;
    cin >> player1;
    if (player1 == 'x')
        player2 = 'o';
    else
        player2 = 'x';

    printBoard();

    cout << "     The Game starts Now\n";
    cout << "Player 1 is: " << player1 << " and Player 2 is: " << player2 << "\n\n";
    // Start of Playing *-*
    while (noOfCells < 9)
    {
        if (player == '2')
        {
            player = '1';
            cout << "Player 1: " << player1 << " ,Enter your play \'Position\' by-> row,space then col (1, 2 or 3)" << endl;
            c = player1;
        }
        else
        {
            player = '2';
            cout << "Player 2: " << player2 << " ,Enter your play \'Position\' by-> row,space then col (1, 2 or 3)" << endl;
            c = player2;
        }
        do
        {
            while (!(cin >> row >> col))
            {
                cout << "Enter your play \'Position\' by-> row,space then col (1, 2 or 3)\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // check if the place in the board is empty!
            while (checkNoTEmptyPlace(row, col))
            {
                while (!(cin >> row >> col))
                {
                    cout << "Enter your play \'Position\' by-> row,space then col (1, 2 or 3)\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        } // check if the place outside the board!
        while (checkInputOutSide(row, col));

        // draw the Board
        drawBoard(c, row - 1, col - 1);
        noOfCells++;

        // check the winner
        if (checkWin(arr) == 'x')
        {
            if (player1 == 'x')
            {
                printPlayer(1);
                return 0;
            }
            else
            {
                printPlayer(2);
                return 0;
            }
        }
        else if (checkWin(arr) == 'o')
        {
            if (player1 == 'o')
            {
                printPlayer(1);
                return 0;
            }
            else
            {
                printPlayer(2);
                return 0;
            }
        }
    }

    if (noOfCells == 9)
        cout << "*_*_* The Game Ended and No one wins *_*_*";

    return 0;
}
