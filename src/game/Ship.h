#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>

class Ship {
private:
	sf::ConvexShape shape;
	sf::Vector2f velocity;
public:
	Ship();
	void draw(sf::RenderWindow& window);
	void update(float dt, sf::Vector2u windowSize);

	void setShape(const sf::ConvexShape& shape) { this->shape = shape; }
	sf::ConvexShape getShape() const { return this->shape; }
	void setVelocity(const sf::Vector2f& velocity) { this->velocity = velocity; }
	sf::Vector2f getVelocity() const { return this->velocity; }
};

#endif // !SHIP_H

