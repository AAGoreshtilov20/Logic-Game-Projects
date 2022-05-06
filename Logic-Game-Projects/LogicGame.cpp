#include <iostream>
#include <iomanip>
#include <string>
#include<cstdlib>
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
    string row[6] = { " _____ ", "|^   ^|", "", "", "|  |  |", "|_____|" };
}
def, fd[2][5][5], hand[2][6]; //default var; field var [player(1 or 2)][row][card], hand var [player(1 or 2)][card]

string empty(bool b) 
{
    if (b)
    {
        return "       "; //7 spaces (replaces a card)
    }
    else
    {
        return "     "; //5 spaces (space between cards)
    }
}

void rowGen3(int cNum) 
{
    for (int i = 0; i < 4; i++)
    {
        cout << empty(0);
        if (fd[pl][rNum][i].val != NULL)
        {
            cout << "|  " << fd[pl][rNum][i].val << "  |";
        }
        else
        {
            cout << "  #" << i + cNum << "   ";
        }
    }
}
void rowGen2()
{
    for (int i = 0; i < 4; i++)
    {
        cout << empty(0);
        if (fd[pl][rNum][i].val != NULL)
        {
            cout << "| " << fd[pl][rNum][i].name << " |";
        }
        else
        {
            cout << empty(1);
        }
    }
}
void rowGen1(int rowS) //rowS = row Specific; cNum = empty card's UI number
{
    for (int i = 0; i < 4; i++)
    {
        cout << empty(0);
        if (fd[pl][rNum][i].val != NULL)
        {
            cout << def.row[rowS];
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

        for (int z = 0; z < 5; z++)
        {
            cout << empty(0) << def.row[5];
        }
        cout << endl << endl;
        break;

    case 1:
        rowGen1(0);
        rowGen1(1);
        rowGen2();
        rowGen3(1);
        rowGen1(4);
        rowGen1(5);
        cout << endl;
        break;

    case 2:
        rowGen1(0);
        rowGen1(1);
        rowGen2();
        rowGen3(5);
        rowGen1(4);
        rowGen1(5);
        cout << endl;
        break;

    case 3:
        rowGen1(0);
        rowGen1(1);
        rowGen2();
        rowGen3(8);
        rowGen1(4);
        rowGen1(5);
        cout << endl;
        break;

    case 4:
        rowGen1(0);
        rowGen1(1);
        rowGen2();
        rowGen3(10);
        rowGen1(4);
        rowGen1(5);
        cout << endl;
        break;
    }
    cout << endl;
}
void fieldGen()
{
    for (int i = 0; i < 5; i++)
    {
        rGen();
        rNum = i;
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
        fd[pl][y][z].name = "or ";
    }
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
        pl = 1;
        turn(); //start of player1's turn

        pl = 2;
        turn(); //start of player2's turn
    }
}