#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

#define Max_main_menu 4

class MainMenu
{
	public://Acsess outside of Class
		MainMenu(float width, float height);

		void draw(RenderWindow& window);
		void MoveUp();
		void MoveDown();

		int MainMenuPressed()
		{
			return MainMenuSelected;
		}

		~MainMenu();

	private://No acsess outside of Class
		int MainMenuSelected;

		Font font;
		Text mainMenu[Max_main_menu];

};
