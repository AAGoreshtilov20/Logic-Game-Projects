#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "MainMenu.h"

using namespace std;
using namespace sf;

void main()
{
	//Main Winow
	RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
	MENU.setView(View(FloatRect(0.0f, 0.0f, 960.0f, 720.0f)));
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	//Audio
	Music Music;
	if (!Music.openFromFile("Music/CaravanToMemphis.wav"))
	{
		cout << "Error! Music Not Found!";
	}

	Music.play();
	Music.setLoop(true);


	//set background
	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	Texture Maintexture;
	Maintexture.loadFromFile("Img/Background.png");
	background.setTexture(&Maintexture);

	//background to the Game
	RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(960, 720));
	Texture option_texture;
	option_texture.loadFromFile("Img/Table.png");
	Pbackground.setTexture(&option_texture);

	//background to the Options
	RectangleShape Obackground;
	Obackground.setSize(Vector2f(960, 720));
	Texture options_texture;
	option_texture.loadFromFile("Img/Background.png");
	Obackground.setTexture(&options_texture);

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
							OPTIONS.close();
							Exit.close();
							HowToPlay.close();
							Play.clear();
							Play.draw(Pbackground);
							Play.display();

							Event aevent;

							while (Play.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Play.close();
								}

								else if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::G)
									{
										Play.close();
									}
								}

							}
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


								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::G)
									{
										OPTIONS.close();
									}
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


									if (aevent.type == Event::KeyPressed)
									{
										if (aevent.key.code == Keyboard::G)
										{
											HowToPlay.close();
										}
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
							if (Exit.isOpen())
							{
								break;
							}
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