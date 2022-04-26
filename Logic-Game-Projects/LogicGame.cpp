#include <iostream>
#include <string>
using namespace std;

//Legend:
//r = row
//gen = generation, generating
//0th row = the five preset bools for each player
//[x][y][z] = [player][row][card] respectfully !!!only when context = pl variable!!!; in normal for-s x, y, z are used as normal dimensions
//"pl" is an array and "p" is a variable in some functuions, both associated with the player
//UI: a = and, o = or, x = xor, n = not
//Meaning of values in pl: and0 = 10, and1 = 11, or0 = 20, or1 = 21, xor0 = 30, xor1 = 31

string pl[2][5][5]; //player var [player(1 or 2)][row][card]; not all cards are going to be used!
int pos; //the next to be placed card's position
bool val; //value for card
char card; //name of card (and, or, xor)
char nothing;

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
        cout << "      ";
        for (int z = 0; z < 4; z++)
        {
            cout << "    ";
            if (pl[p][1][z] != "0")
            {
                cout << "|" <<  pl[p][1][z] << "|";
            }
            else
            {
                cout << " #" << z + 1 << " ";
            }
        }
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

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
    fieldGen(p); //gen visuals
    cout << " Which card do you want to place? ";
    cin >> card;
    cout << endl << " What is its value? ";
    cin >> val;
    cout << endl << " Where do you want to place it? ";
    cin >> pos;
    system("CLS"); //cout << card << val << pos << endl; <- for testing
    
    switch (pos)
    {
    case 1:
        pl[p][1][0] = card + char(val);
        break;
    }

    fieldGen(p);
    cin >> nothing;
    system("CLS"); //end of turn
}

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
                pl[x][y][z] = '0';
            }
        }
    }

    while(true) //start of game
    {
        turn(0); //start of player1's turn
        turn(1); //start of player2's turn        
    }
}