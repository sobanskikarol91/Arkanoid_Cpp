#pragma once
#include "Obrazek.h"
#include "IReset.h"

class Paletka : public Obrazek, IReset
{
	Vector2f startowa_pozycja;

public:
	Paletka() {}
	Paletka(Texture * tekstura, Vector2f pozycja) : Obrazek(tekstura), startowa_pozycja(pozycja)
	{
		sprite.setPosition(pozycja);
	}

	void ruch(Vector2f kierunek)
	{
		sprite.move(kierunek);
	}

	void reset() override
	{
		sprite.setPosition(startowa_pozycja);
	}
};

