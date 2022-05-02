#include <iostream>
#include <iomanip>
#include <string>
#include<cstdlib>
using namespace std;

//Legend:
//r = row
//gen = generation, generating
//0th row = the five preset bools for each player
//[x][y][z] = [player][row][card] respectfully !!!only when context = pl variable!!!; in normal for-s x, y, z are used as normal dimensions
//"pl" is an array and "p" is a variable in some functuions, both associated with the player
//UI: a = and, o = or, x = xor, n = not
//Meaning of values in pl: and 0 = 10, and 1 = 11, or 0 = 20, or 1 = 21, xor 0 = 30, xor 1 = 31

int pl[2][5][5]; //player var [player(1 or 2)][row][card]; not all cards are going to be used!
int pos; //the next to be placed card's position
bool val; //value for card
char nothing;
string card; //name of card (and, or, xor)

void empty()
{
    cout << "        "; //5 spaces margin on left side, 3 for missing card
}

void r(int p, int rNum)
{
    switch (rNum)
    {
    case 0:
        for (int z = 0; z < 5; z++)
        {
            cout << "      |" << pl[p][0][z] << "|"; //5 spaces infront
        }
        break;
    case 1:
        cout << setw(10);
        for (int z = 0; z < 4; z++)
        {
            cout << "     ";
            if (pl[p][1][z] != 0)
            {
                cout << "|" << pl[p][0][z] << "|";
            }
            else
            {
                cout << " #" << z + 1 << " ";
            }
        }
        break;
    case 2:
        cout << setw(14);
        for (int z = 0; z < 3; z++)
        {
            cout << "     ";
            if (pl[p][2][z] != 0)
            {
                cout << "|" << pl[p][0][z] << z << "|";
            }
            else
            {
                cout << " #" << z + 5 << " ";
            }
        }
        break;
    case 3:
        cout << setw(18);
        for (int z = 0; z < 2; z++)
        {
            cout << "     ";
            if (pl[p][3][z] != 0)
            {
                cout << "|" << pl[p][0][z] << "|";
            }
            else
            {
                cout << " #" << z + 8 << " ";
            }
        }
        break;
    case 4:
        cout << setw(26);
        if (pl[p][4][0] != 0)
        {
            cout << "|" << pl[p][0][0] << "|";
        }
        else
        {
            cout << " #10";
        }
        break;
    }
    cout << endl;
}
void fieldGen(int p)
{
    for (int x = 0; x < 5; x++)
    {
        r(p, x);
    }
}

void turn(int p)
{
    int y, z;

    fieldGen(p); //gen visuals
    cout << "\n\n Which card do you want to place? ";
    cin >> card;
    cout << " What is its value? ";
    cin >> val;
    cout << " Where do you want to place it? ";
    cin >> pos;
    system("CLS"); //cout << card << val << pos << endl; <- for testing

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
    
    if (card == "and")
    {
        if (val == 0)
        {
            pl[p][y][z] = 10;
        }
        else
        {
            pl[p][y][z] = 11;
        }
    }
    else if (card == "or")
    {
        if (val == 0)
        {
            pl[p][y][z] = 20;
        }
        else
        {
            pl[p][y][z] = 21;
        }
    }
    else if (card == "xor")
    {
        if (val == 0)
        {
            pl[p][y][z] = 30;
        }
        else
        {
            pl[p][y][z] = 31;
        }
    }

    fieldGen(p);
    cin >> nothing;
    system("CLS"); //end of turn
}

void draw()

int main()
{
    srand(time(NULL)); //call srand once to get random seed from time

    for (int x = 0; x < 2; x++) //gen 0th row nums
    {
        for (int z = 0; z < 5; z++)
        {
            pl[x][0][z] = rand() % 2; //cout << x << 0 << z << pl[x][0][z] << endl; <- for testing   
        }
    }
    for (int x = 0; x < 2; x++) //gen empty rows and cards nums
    {
        for (int y = 1; y < 5; y++) //y = 1 cuz not counting 0th row
        {
            for (int z = 0; z < 5; z++)
            {
                pl[x][y][z] = 0;
            }
        }
    }

    while(true) //start of game
    {
        turn(0); //start of player1's turn
        turn(1); //start of player2's turn        
    }
}