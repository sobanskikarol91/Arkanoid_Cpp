#pragma once
#include "Obrazek.h"

class Paletka : public Obrazek
{
public:
	Paletka() {}
	Paletka(Texture * tekstura, Vector2f pozycja) : Obrazek(tekstura)
	{
		sprite.setPosition(pozycja);
	}

	void ruch(Vector2f kierunek)
	{
		 sprite.move(kierunek);
	}
};

