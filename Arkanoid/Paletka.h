#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Paletka :public Drawable
{
	Sprite sprite;

public:
	Paletka() {};
	Paletka(Texture * tekstura, Vector2f pozycja) : sprite(*tekstura)
	{
		sprite.setPosition(pozycja);
	}
	// opisuje jak ma byc rysowany obiekt. Musi byc zaimplementowane z Interfejsu Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override
	{
		// rysujemy sprite
		target.draw(sprite);
	}

	void ruch(Vector2f kierunek)
	{
		 sprite.move(kierunek);
		// if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) dy = -(rand() % 5 + 2);
	}
};

