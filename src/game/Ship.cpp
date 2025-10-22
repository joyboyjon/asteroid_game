#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Constants.h"

Ship::Ship() : velocity(0.f, 0.f) {
	shape.setPointCount(3);
	shape.setPoint(0, { 32,0 });
	shape.setPoint(1, { 0,64 });
	shape.setPoint(2, { 64,64 });
	shape.setOrigin({ 32.f,32.f });
	shape.setPosition({ WINDOW_WIDTH/2.f,WINDOW_HEIGHT/2.f });
	velocity = { 0,0 };
}

void Ship::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

void Ship::update(float dt,sf::Vector2u windowSize) {
	sf::Vector2f curVelocity = getVelocity();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) { curVelocity.x += SHIP_SPEED * dt; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) { curVelocity.x -= SHIP_SPEED * dt; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) { curVelocity.y -= SHIP_SPEED * dt; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) { curVelocity.y += SHIP_SPEED * dt; }

	curVelocity *= FRICTION;

	setVelocity(curVelocity);

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