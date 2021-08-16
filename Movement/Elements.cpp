#include "Elements.h"

Element::Element(Vector2i position, Vector2i velocity, Vector2i acceleration, SDL_Color color) : position(position), velocity(velocity), acceleration(acceleration), color(color)
{

}

SDL_Color Element::getColor()
{
	return color;
}

Vector2i Element::getPosition()
{
	return position;
}

Vector2i Element::getVelocity()
{
	return velocity;
}

Vector2i Element::getAcceleration()
{
	return acceleration;
}

void Element::setPosition(Vector2i in)
{
	position = in;
}

void Element::setVelocity(Vector2i in)
{
	velocity = in;
}

void Element::setAcceleration(Vector2i in)
{
	acceleration = in;
}
