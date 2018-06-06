#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Pilka :public  Drawable
{
	Sprite sprite;
	Vector2f predkosc; // z jaka porusza sie pilka
public:
	Pilka() {}
	Pilka(Texture * tekstura, Vector2f pozycja, Vector2f predkosc) : sprite(*tekstura), predkosc(predkosc)
	{
		sprite.setPosition(pozycja);
	};

	// opisuje jak ma byc rysowany obiekt. Musi byc zaimplementowane z Interfejsu Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override
	{
		target.draw(sprite);
	}

	void ruch(Vector2u * granica)
	{
		Vector2f nowe_polozenie = sprite.getPosition() + predkosc;

		if (nowe_polozenie.x < 0 || nowe_polozenie.x > granica->x)  predkosc.x = -predkosc.x;
		if (nowe_polozenie.y < 0 || nowe_polozenie.y > granica->y)  predkosc.y = -predkosc.y;
		sprite.setPosition(nowe_polozenie);
	}
};

