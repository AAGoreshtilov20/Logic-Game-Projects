#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

using namespace std;
using namespace sf;

#define Max_main_menu 4 //max main menu buttons

class MainMenu
{
public://Acsess outside of Class
    MainMenu(float width, float height);

    void draw(RenderWindow& window);
    void MoveUp();//Move Up to other option
    void MoveDown();//Move Down to other option

    int MainMenuPressed() //When a button is pressed do:
    {
        return MainMenuSelected;
    }

    ~MainMenu();

private://No acsess outside of Class
    int MainMenuSelected;

    Font font;
    Text mainMenu[Max_main_menu];

};
