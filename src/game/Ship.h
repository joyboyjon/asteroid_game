#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>

class Ship {
private:
	sf::ConvexShape shape;
	sf::Vector2f velocity;
	float rotation;
public:
	Ship();
	void draw(sf::RenderWindow& window);
	void update(float dt, sf::Vector2u windowSize);
	void accelerate(float dt);

	void setShape(const sf::ConvexShape& shape) { this->shape = shape; }
	sf::ConvexShape getShape() const { return this->shape; }
	void setVelocity(const sf::Vector2f& velocity) { this->velocity = velocity; }
	sf::Vector2f getVelocity() const { return this->velocity; }
	void setRotation(const float& rotation) { this->rotation = rotation; }
	float getRotation() const { return this->rotation; }
};

#endif // !SHIP_H

