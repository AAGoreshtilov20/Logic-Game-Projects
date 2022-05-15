#include "MainMenu.h"

//Constructors & Destructors
MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("GameFonts/Oswald-Regular.ttf"))
	{
		cout << "Error. Font Not Found!" << endl;
	} //font needs to be downloaded to work!!


//Play button
mainMenu[0].setFont(font);
mainMenu[0].setFillColor(Color::White);
mainMenu[0].setString("Play");
mainMenu[0].setCharacterSize(70);
mainMenu[0].setPosition(400, 200);

//Options Button
mainMenu[1].setFont(font);
mainMenu[1].setFillColor(Color::White);
mainMenu[1].setString("Options");
mainMenu[1].setCharacterSize(70);
mainMenu[1].setPosition(400, 300);

//How to play Button
mainMenu[2].setFont(font);
mainMenu[2].setFillColor(Color::White);
mainMenu[2].setString("How to Play");
mainMenu[2].setCharacterSize(70);
mainMenu[2].setPosition(400, 400);

//Exit button
mainMenu[3].setFont(font);
mainMenu[3].setFillColor(Color::White);
mainMenu[3].setString("Exit");
mainMenu[3].setCharacterSize(70);
mainMenu[3].setPosition(400, 500);

MainMenuSelected = -1;
};

MainMenu::~MainMenu()
{

}
//DrawMainMenu
void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(mainMenu[i]);
	}
}

//MoveUp
void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;

		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

//MoveDown
void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);
	}
	
	MainMenuSelected++;

	if (MainMenuSelected == 4)
	{
		MainMenuSelected = 0;
	}

	mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}