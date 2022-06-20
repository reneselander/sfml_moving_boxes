#include <SFML/Graphics.hpp>

int WinMain()

{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;


	sf::RenderWindow window(sf::VideoMode(1280, 720), "Moving Boxes", sf::Style::Default, settings);
	//sf::Window window;
	//window.create(sf::VideoMode(800, 600), "Moving Square");


	/*
	Eller skapa ett fönster så här går också:
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My Program");
	*/



	window.setFramerateLimit(60);

	// Skapa box 1
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(112, 130, 56));

	// Bestäm storleken på box 1, i pixlar
	rect.setSize(sf::Vector2f(60, 60));

	// Skapa start-positionen för box 1, 
	sf::Vector2f rectanglePosition(300, 300);
	rect.setPosition(rectanglePosition);



	// Skapa box 2
	sf::RectangleShape rect2;
	rect2.setFillColor(sf::Color(117, 109, 71));
	//rect2.setFillColor(sf::Color::Red);

	// Bestäm storleken på objektet, i pixlar
	rect2.setSize(sf::Vector2f(20, 20));

	// Skapa start-positionen för box 2, 
	sf::Vector2f rectanglePosition2(300, 200);
	rect2.setPosition(rectanglePosition2);



	// Skapa box 3
	sf::RectangleShape rect3;
	//rect3.setFillColor(sf::Color(117, 109, 71));
	rect3.setFillColor(sf::Color::Red);

	// Bestäm storleken på objektet, i pixlar
	rect3.setSize(sf::Vector2f(40, 20));

	// Skapa start-positionen för box 3, 
	sf::Vector2f rectanglePosition3(600, 400);
	rect3.setPosition(rectanglePosition3);





	// Box 1 hastighet (pixlar / sekund)
	float xVelocity = 5;
	float yVelocity = 5;


	// Box 2 hastighet (pixlar / sekund)
	float xVelocity2 = 3;
	float yVelocity2 = 3;

	// Box 3 hastighet (pixlar / sekund)
	float xVelocity3 = 1;
	float yVelocity3 = 1;

	// Slut på dom första variablerna

	// Här börjar loopen eller själva programmet med while-loop (så länge som bl.a. bl.a. bl.a.)


	while (window.isOpen())

	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			// Här en if-sats som gör att fönstret stängs när man klickar på X i övre högra hörnet.
			if (event.type == sf::Event::Closed) window.close();

			// Här en if-sats som gör att fönstret stängs när Esc-knappen trycks ner.
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

		}

		// Physics, kollisions-funktion... "när objektet kör in i väggen". Använder en offset på -60 pixlar till höger och ovanför om objektet
		// x = vänster, höger, y = upp, ner
		if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - 60) xVelocity *= -1;
		if (rectanglePosition.y < 0 || rectanglePosition.y > 720 - 60) yVelocity *= -1;

		if (rectanglePosition2.x < 0 || rectanglePosition2.x > 1280 - 20) xVelocity2 *= -1;
		if (rectanglePosition2.y < 0 || rectanglePosition2.y > 720 - 20) yVelocity2 *= -1;

		if (rectanglePosition3.x < 0 || rectanglePosition3.x > 1280 - 40) xVelocity3 *= -1;
		if (rectanglePosition3.y < 0 || rectanglePosition3.y > 720 - 20) yVelocity3 *= -1;

		rectanglePosition.x += xVelocity;
		rectanglePosition.y += yVelocity;
		rect.setPosition(rectanglePosition);

		rectanglePosition2.x += xVelocity2;
		rectanglePosition2.y += yVelocity2;
		rect2.setPosition(rectanglePosition2);

		rectanglePosition3.x += xVelocity3;
		rectanglePosition3.y += yVelocity3;
		rect3.setPosition(rectanglePosition3);

		// Plats för kollisions-funktionen




		// Color(red, green, blue, alpha)
		//https://rgbacolorpicker.com/
		window.clear(sf::Color(211, 205, 208, 0.2));

		window.draw(rect);
		window.draw(rect2);
		window.draw(rect3);

		window.display();

	}

	return 0;

}