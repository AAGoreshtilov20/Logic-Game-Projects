#include <iostream>
#include <string>
#include <cstdlib>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600, 600), "BuuLeoGame.exe", Style::Default);
	Event e;

	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			switch (e.type) // closing window
			{
				case Event::Closed:
					window.close();

			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape) == true)// closing window
			{
				window.close();
			}


			if (e.type == Event::Closed)
				window.close();
		}
	}
	//mouse::isButtonPressed;

	return 0;
}