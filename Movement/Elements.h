#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include <iostream>

struct Vector2i
{
	double x, y;
	Vector2i(double x, double y) :x(x), y(y) {}
	Vector2i(std::vector<double> vec) { x = vec[0]; y = vec[1]; }
	Vector2i(std::pair<double, double> p) { x = p.first; y = p.second; }
	Vector2i operator+(Vector2i v) { return Vector2i(x + v.x, y + v.y); }
	Vector2i operator-(Vector2i v) { return Vector2i(x - v.x, y - v.y); }
	Vector2i operator*(double d) { return Vector2i(x * d, y * d); }
};

class Element
{
public:
	Element(Vector2i position, Vector2i velocity, Vector2i acceleration, SDL_Color color);
	SDL_Color getColor();
	Vector2i getPosition();
	Vector2i getVelocity();
	Vector2i getAcceleration();
	void setPosition(Vector2i in);
	void setVelocity(Vector2i in);
	void setAcceleration(Vector2i in);

	virtual void Update(std::vector<Element*>* el) = 0;
	virtual void Render() = 0;

private:
	Vector2i position, velocity, acceleration;
	SDL_Color color;
};

