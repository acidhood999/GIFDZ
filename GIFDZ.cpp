// GIFDZ.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

void circle(Shape& shape) {
	shape.setPosition(shape.getPosition().x + 4, shape.getPosition().y + 4);
}
void circleMgnum(CircleShape& shape, CircleShape& shape2, RenderWindow& window) {
	if (shape.getPosition().x <= 0) {
		shape2.setPosition((float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x < (1 - (float)window.getSize().x)) {
			shape.setPosition(0, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y <= 0) {
		shape2.setPosition(shape2.getPosition().x, (float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y < (1 - (float)window.getSize().y)) {
			shape.setPosition(shape.getPosition().x, 0);
		}
	}
	if (shape.getPosition().x + shape.getRadius() * 2 >= window.getSize().x) {
		shape2.setPosition(-(float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x + shape.getRadius() * 2 - (float)window.getSize().x > window.getSize().x) {
			shape.setPosition(-shape.getRadius() * 2, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y + shape.getRadius() * 2 >= window.getSize().y) {
		shape2.setPosition(shape2.getPosition().x, -(float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y + shape.getRadius() * 2 - (float)window.getSize().x > window.getSize().y) {
			shape.setPosition(shape.getPosition().x, -shape.getRadius() * 2);
		}
	}
}

void circle1(Shape& shape) {
	shape.setPosition(shape.getPosition().x + 4, shape.getPosition().y + 0);
}
void circleMgnum1(RectangleShape& shape, RectangleShape& shape2, RenderWindow& window) {
	if (shape.getPosition().x <= 0) {
		shape2.setPosition((float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x < (1 - (float)window.getSize().x)) {
			shape.setPosition(0, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y <= 0) {
		shape2.setPosition(shape2.getPosition().x, (float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y < (1 - (float)window.getSize().y)) {
			shape.setPosition(shape.getPosition().x, 0);
		}
	}
	if (shape.getPosition().x + shape.getRotation() * 2 >= window.getSize().x) {
		shape2.setPosition(-(float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x + shape.getRotation() * 2 - (float)window.getSize().x > window.getSize().x) {
			shape.setPosition(-shape.getRotation() * 2, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y + shape.getRotation() * 2 >= window.getSize().y) {
		shape2.setPosition(shape2.getPosition().x, -(float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y + shape.getRotation() * 2 - (float)window.getSize().x > window.getSize().y) {
			shape.setPosition(shape.getPosition().x, -shape.getRotation() * 2);
		}
	}
}

int main()
{
	
	RenderWindow window(VideoMode(400, 400), "Lesson 2. kychka-pc.ru");
	window.setFramerateLimit(60);

	CircleShape shape(100.f);
	RectangleShape rect(Vector2f(150, 100));

	//shape.setFillColor(sf::Color::Red);


	Texture texturePryam;
	texturePryam.loadFromFile("kartinki/kvadrat.jpeg");
	rect.setTexture(&texturePryam);
	RectangleShape rect3;
	rect3 = rect;
	rect3.setPosition((Vector2f)window.getSize());
	
	


	
	

	Texture textureFont;
	textureFont.loadFromFile("kartinki/fon.jpeg");
	RectangleShape recShape(Vector2f(window.getSize()));
	recShape.setTexture(&textureFont);


	Texture textureCircle;
	textureCircle.loadFromFile("kartinki/kryg.jpeg");
	shape.setTexture(&textureCircle);
	CircleShape shape2;
	shape2 = shape;
	shape2.setPosition((Vector2f)window.getSize());

	
	int x = 0, y = 0;
	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		


		circleMgnum(shape, shape2, window);
		circle(shape);
		circleMgnum1(rect, rect3, window);
		circle1(rect);
		window.clear();
		window.draw(recShape);
		window.draw(shape);
		window.draw(shape2);
		window.draw(rect);
		window.draw(rect3);
		window.display();
	}

	return 0;
}