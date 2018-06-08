#pragma once
#include "Obrazek.h"
#include "IReset.h"

class Paletka : public Obrazek, IReset
{
	Vector2f startowa_pozycja;

public:
	Paletka();
	Paletka(Texture * tekstura, Vector2f pozycja);
	void ruch(Vector2f kierunek, Vector2u  granica); // granica gdize moze sie poruszac paletka wielkosc ekranu 
	void reset() override;
};

