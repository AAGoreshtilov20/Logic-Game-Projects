#include <iostream>
#include <string>
using namespace std;

//Legend:
// r = row
// gen = generation, generating
// 0th row = the five preset bools for each player
// [x][y][z] = [player][row][card] respectfully !!!only when context = pl variable!!!; in normal for-s x, y, z are used as normal dimensions

int rNull = 1; // value = smallest number of empty row
int pl[2][5][5]; // player var [player(1 or 2)][row][card]; not all cards are going to be used!; float cuz of rng complicated reasons

void empty()
{
    cout << "        "; // 5 spaces margin on left side, 3 for missing card
}

void r(int player, int rNum)
{
    switch (rNum)
    {
    case 0:
        for (int z = 0; z < 5; z++)
        {
            cout << "     |" << pl[player][0][z] << "|";
        }
        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    }
}
void fieldGen(int player)
{
    for (int x = 0; x < rNull; x++)
    {
        r(player, x);
    }
}

int main()
{
    string card;
    int random;

    srand(time(NULL)); //call srand once to get random seed from time

    for (int x = 0; x < 2; x++) // gen 0th row nums
    {
        for (int z = 0; z < 5; z++)
        {           
            pl[x][0][z] = rand() % 2; //cout << x << 0 << z << pl[x][0][z] << endl; <- for testing   
        }
    }
    for (int x = 0; x < 2; x++) // gen empty rows and cards nums
    {
        for (int y = 1; y < 5; y++) // y = 1 cuz not counting 0th row
        {
            for (int z = 0; z < 5; z++)
            {
                pl[x][y][z] = 0;
            }
        }
    }

    while (true) // start of turn of player 1
    {
        for (int x = 0; x < 2; x++) // check for rNull
        {
            for (int y = 1; y < 5; y++) // y = 1 cuz not counting 0th row
            {
                for (int z = 0; z < 5; z++)
                {
                    if (pl[x][y][z] != 0)
                    {
                        rNull = y + 1;
                    }
                }
            }
        }

        fieldGen(0); // gen visuals

        getline(cin, card);
    }

}