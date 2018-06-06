#pragma once
#include <SFML/Graphics.hpp>
class Pilka :public  Drawable
{
	Sprite sprite;
	float szybkosc; // z jaka porusza sie pilka
public:
	Pilka() {}
	Pilka(Texture tekstura, Vector2f pozycja, float szybkosc) : sprite(tekstura), szybkosc(szybkosc)
	{
		sprite.setPosition(pozycja);
	};

	// opisuje jak ma byc rysowany obiekt. Musi byc zaimplementowane z Interfejsu Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override
	{
		target.draw(sprite);
	}
};

