#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Paletka
{
	Sprite sprite;

public:
	Paletka() {};
	Paletka(Texture * tekstura, Vector2f pozycja) : sprite(*tekstura)
	{
		sprite.setPosition(pozycja);
	}
};

