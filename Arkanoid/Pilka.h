#pragma once
#include "Obrazek.h"

class Pilka :public  Obrazek
{
	Vector2f predkosc; // z jaka porusza sie pilka
public:
	Pilka() {}
	Pilka(Texture * tekstura, Vector2f pozycja, Vector2f predkosc) :Obrazek(tekstura), predkosc(predkosc)
	{
		sprite.setPosition(pozycja);
	};

	// poruszanie sie pilki
	void ruch(Vector2u * granica)
	{
		Vector2f nowe_polozenie = sprite.getPosition() + predkosc;

		if (nowe_polozenie.x < 0 || nowe_polozenie.x > granica->x)  predkosc.x = -predkosc.x;
		if (nowe_polozenie.y < 0 || nowe_polozenie.y > granica->y)  predkosc.y = -predkosc.y;
		sprite.setPosition(nowe_polozenie);
	}

	// przy kolizji z cegielka
	void odbijWPoziomie()
	{
		predkosc.y *= -1;
	}
};

