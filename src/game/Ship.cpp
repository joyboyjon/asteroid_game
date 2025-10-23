#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Constants.h"

Ship::Ship() : velocity(0.f, 0.f),rotation(0.f) {
	shape.setPointCount(3);
	shape.setPoint(0, { 32,0 });
	shape.setPoint(1, { 0,64 });
	shape.setPoint(2, { 64,64 });
	shape.setOrigin({ 32.f,32.f });
	shape.setPosition({ WINDOW_WIDTH/2.f,WINDOW_HEIGHT/2.f });
}

void Ship::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

void Ship::accelerate(float dt) {
	sf::Angle rotation = shape.getRotation();
	float angleRad = rotation.asRadians()- PI / 2.f;
	sf::Vector2f direction(std::cos(angleRad), std::sin(angleRad));

	velocity += direction * SHIP_ACCELERATION * dt;
	velocity *= FRICTION;

	float speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
	if (speed > MAX_SPEED)
		velocity = (velocity / speed) * MAX_SPEED;

}

void Ship::update(float dt,sf::Vector2u windowSize) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) { shape.rotate(sf::degrees(-ROTATION_SPEED * dt)); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) { shape.rotate(sf::degrees(ROTATION_SPEED * dt)); }


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) { accelerate(dt); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) { velocity *= 0.99f; }

	shape.move(dt * velocity);
	
	sf::Vector2f pos = shape.getPosition();
	sf::FloatRect bounds = shape.getGlobalBounds();
	sf::Vector2f size = bounds.size;
	//right margin
	if (pos.x-size.x/2-MARGIN> windowSize.x) pos.x =-size.x/2-MARGIN;
	//left margin
	else if (pos.x + size.x / 2 + MARGIN<0) pos.x = windowSize.x+size.x/2+MARGIN;
	//lower margin
	if (pos.y-size.y/2-MARGIN > windowSize.y) pos.y = -size.y/2-MARGIN;
	//upper margin
	else if (pos.y+size.y/2+MARGIN< 0) pos.y = windowSize.y+size.y/2+MARGIN;


	shape.setPosition(pos);
}