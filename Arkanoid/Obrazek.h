#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Obrazek : public Drawable
{
protected:
	Sprite sprite;
	Obrazek() {}
	Obrazek(Texture * tekstura) : sprite(*tekstura) {}

public:
	FloatRect pobierz_wymiary()
	{
		return sprite.getGlobalBounds();
	}

	void Schowaj()
	{
		sprite.setPosition(1000, 1000);
	}
	// opisuje jak ma byc rysowany obiekt. Musi byc zaimplementowane z Interfejsu Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override
	{
		target.draw(sprite);
	}
};

