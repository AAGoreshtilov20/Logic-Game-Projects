#include <iostream>
#include "SFML/Graphics.hpp"
#include "MainMenu.h"

using namespace std;
using namespace sf;

void main()
{
	//Main Winow

	RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
	//set background
	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	Texture Maintexture;
	Maintexture.loadFromFile("Img/Background.png");
	background.setTexture(&Maintexture);

	//background to the game
	RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(960, 720));
	Texture back_texture;
	back_texture.loadFromFile("Img/Background.png");
	Pbackground.setTexture(&back_texture);

	//background to the Options
	RectangleShape Obackground;
	Obackground.setSize(Vector2f(960, 720));
	Texture option_texture;
	option_texture.loadFromFile("Img/Background.png");
	Obackground.setTexture(&option_texture);

	//background to the HowToPlay
	RectangleShape HtPbackground;
	HtPbackground.setSize(Vector2f(960, 720));
	Texture HowToPlay_texture;
	HowToPlay_texture.loadFromFile("Img/Background.png");
	HtPbackground.setTexture(&HowToPlay_texture);

	while (MENU.isOpen())
	{
		Event event;

		while (MENU.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MENU.close();
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}

				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}

				if (event.key.code == Keyboard::Return)
				{
					RenderWindow Play(VideoMode(960, 720), "Play");
					RenderWindow OPTIONS(VideoMode(960, 720), "OPTIONS");
					RenderWindow HowToPlay(VideoMode(960, 720), "How To Play");
					RenderWindow Exit(VideoMode(960, 720), "Exit");

					int x = mainMenu.MainMenuPressed();

					if (x == 0)
					{
						while (Play.isOpen())
						{
							Event aevent;

							while (Play.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Play.close();
								}
							}

							if (aevent.type == Event::KeyPressed)
							{
								if (aevent.key.code == Keyboard::Escape)
								{
									Play.close();
								}
							}
							OPTIONS.close();
							Exit.close();
							HowToPlay.close();
							Play.clear();

							Play.display();
						}
					}

					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							Event aevent;

							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();
								}
							}

							if (aevent.type == Event::KeyPressed)
							{
								if (aevent.key.code == Keyboard::Escape)
								{
									OPTIONS.close();
								}
							}
							Play.close();
							HowToPlay.close();
							Exit.close();
							OPTIONS.clear();

							OPTIONS.display();
						}

						if (x == 2)
						{
							while (HowToPlay.isOpen())
							{
								Event aevent;

								while (HowToPlay.pollEvent(aevent))
								{
									if (aevent.type == Event::Closed)
									{
										HowToPlay.close();
									}
								}

								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										HowToPlay.close();
									}
								}
								Play.close();
								OPTIONS.close();
								Exit.close();
								HowToPlay.clear();

								HowToPlay.display();
							}
						}
						if (x == 3)
						{
							MENU.close();
							break;
						}
					}
				}

			}
		}
		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}
}