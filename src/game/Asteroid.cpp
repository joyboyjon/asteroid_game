#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include "Constants.h"

Asteroid::Asteroid(Size size,float startX, float startY) {

	unsigned int points;
	float radius;

	switch (size) {
	case SMALL:
		points = 5;
		radius = 25.f;
		break;
	case MEDIUM:
		points = 7;
		radius = 40.f;
		break;
	case LARGE:
		points = 9;
		radius = 55.f;
		break;
	}

	shape.setPointCount(points);
	for (unsigned int i = 0; i < points; i++) {
		float angle = i * 2.f * PI / points;
		float offsetFactor = static_cast<float>((std::rand() % 31 - 15)) / 100.f;
		float curRadius = radius * (1.f + offsetFactor);

		float x = std::cos(angle) * curRadius;
		float y = std::sin(angle) * curRadius;
		shape.setPoint(i, sf::Vector2f{ x,y });
	}

	shape.setOrigin({radius,radius});
	shape.setPosition({ startX,startY });

	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(2.f);
}

void Asteroid::draw(sf::RenderWindow& window) const {
	window.draw(shape);
}