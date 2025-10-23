#ifndef ASTEROID_H
#define ASTEROID_H
#include <SFML/Graphics.hpp>

class Asteroid {
private:
	sf::ConvexShape shape;
	sf::Vector2f velocity;
	float rotationSpeed;
public:
	enum Size{SMALL, MEDIUM, LARGE};
	Asteroid(Size size,float startX, float startY);

	void update(float dt, sf::Vector2u windowSize);
	void draw(sf::RenderWindow& window) const ;

	sf::Vector2f getPosition() const { return shape.getPosition(); }
	sf::FloatRect getBounds() const { return shape.getGlobalBounds(); }

	sf::ConvexShape getShape() const { return this->shape; }
	void setShape(const sf::ConvexShape& shape) { this->shape = shape; }
	sf::Vector2f getVelocity() const { return this->velocity; }
	void setVelocity(const sf::Vector2f& velocity) { this->velocity = velocity; }
	float getRotationSpeed() const { return this->rotationSpeed; }
	void setRotationSpeed(const float& rotationSpeed) { this->rotationSpeed = rotationSpeed; }
};


#endif // !ASTEROID_H
