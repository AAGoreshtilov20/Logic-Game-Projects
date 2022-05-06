#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Legend:
//r = row of cards; row = row of chars/strings
//gen = generation, generating
//0th row = the five preset bools for each player
//[x][y][z] = [player][row][card] respectfully !!!only when context = pl variable!!!; in normal for-s x, y, z are used as normal dimensions
//"pl" is an array and "p" is a variable in some functuions, both associated with the player
//UI: a = and, o = or, x = xor, n = not
//Meaning of values in pl: and 0 = 10, and 1 = 11, or 0 = 20, or 1 = 21, xor 0 = 30, xor 1 = 31

char nothing;
int pl; //whoose player's turn is
int rNum; //current r's/row's number

struct card
{
    string name; //and, or, xor
    bool val; //value for card
    bool sign = 0;
    string row[6] = { " _____ ", "|^   ^|", "", "", "|__|__|" };
}
def, fd[2][5][5], hand[2][6]; //default var; field var [player(1 or 2)][row][card], hand var [player(1 or 2)][card]

string empty(int b) 
{
    switch(b)
    {
    case 0:
        return "     "; //5 spaces (space between cards)
        break;
    case 1:
        return "       "; //7 spaces (replaces a card)
        break;
    }
}

void front(int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << empty(0) << " ";
    }
}
void rowGen(int row, int cNum) //cNum = empty card's UI number
{
    front(rNum);
    for (int i = 0; i < 5 - rNum; i++)
    {
        cout << empty(0);
        if (fd[pl][rNum][i].sign == 1)
        {
            switch (row)
            {
            case 3:
                cout << "| " << fd[pl][rNum][i].name << " |";
                break;
            case 4:
                cout << "|  " << fd[pl][rNum][i].val << "  |";
                break;
            default:
                int sRow = row - 1;
                cout << def.row[sRow];
                break;
            }
        }
        else if (row == 4)
        {
            cout << "  #" << i + cNum << "   ";
        }
        else
        {
            cout << empty(1);
        }
    }
    cout << endl;
}
void rGen()
{
    switch (rNum)
    {
    case 0:
        for (int z = 0; z < 5; z++)
        {
            cout << empty(0) << def.row[0];
        }
        cout << endl;

        for (int z = 0; z < 5; z++)
        {
            cout << empty(0) << "|  " << fd[pl][rNum][z].val << "  |"; //5 spaces infront
        }
        cout << endl;

        for (int z = 0; z < 5; z++)
        {
            cout << empty(0) << def.row[4];
        }
        cout << endl;
        break;

    case 1:
        for (int i = 1; i < 6; i++)
        {
            rowGen(i, 1);
        }
        break;

    case 2:
        for (int i = 1; i < 6; i++)
        {
            rowGen(i, 5);
        }
        break;

    case 3:
        for (int i = 1; i < 6; i++)
        {
            rowGen(i, 8);
        }
        break;

    case 4:
        for (int i = 1; i < 6; i++)
        {
            rowGen(i, 10);
        }
        break;
    }
}
void fieldGen()
{
    for (int i = 0; i < 5; i++)
    {
        rNum = i;
        rGen();
    }
}

void turn()
{
    int y, z;
    int pos;

    fieldGen(); //gen visuals

    cout << "\n\n Where do you want to place your card? ";
    cin >> pos;
    switch (pos)
    {
    case 1:
        y = 1;
        z = 0;
        break;
    case 2:
        y = 1;
        z = 1;
        break;
    case 3:
        y = 1;
        z = 2;
        break;
    case 4:
        y = 1;
        z = 3;
        break;
    case 5:
        y = 2;
        z = 0;
        break;
    case 6:
        y = 2;
        z = 1;
        break;
    case 7:
        y = 2;
        z = 2;
        break;
    case 8:
        y = 3;
        z = 0;
        break;
    case 9:
        y = 3;
        z = 1;
        break;
    case 10:
        y = 4;
        z = 0;
        break;
    }

    cout << " Which card do you want to place? ";
    cin >> fd[pl][y][z].name;
    cout << " What is its value? ";
    cin >> fd[pl][y][z].val;
    if (fd[pl][y][z].name == "or")
    {
        fd[pl][y][z].name = "oro";
    }
    fd[pl][y][z].sign = 1;
    system("CLS");

    fieldGen();
    cin >> nothing;
    system("CLS"); //end of turn
}

int draw()
{
    return 1 + (rand() % 6); // Retrieve a random number between 1 and 6
}

int main()
{
    srand(time(NULL)); //call srand once to get random seed from time

    for (int z = 0; z < 5; z++)
    {
        fd[0][0][z].val = rand() % 2;
        fd[1][0][z].val = !fd[0][0][z].val;
    }

    while (true) //start of game
    {
        pl = 0;
        turn(); //start of player1's turn

        pl = 1;
        turn(); //start of player2's turn
    }
}