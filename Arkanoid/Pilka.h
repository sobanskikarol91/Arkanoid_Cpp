#pragma once
#include "Obrazek.h"
#include <SFML/Audio.hpp>
#include "IReset.h"
class Pilka :public  Obrazek, IReset
{
	Vector2f predkosc; // z jaka porusza sie pilka
	Vector2f startowa_pozycja;
	Vector2f startowa_predkosc;

public:
	Pilka();
	Pilka(Texture * tekstura, Vector2f pozycja, Vector2f predkosc);
	// poruszanie sie pilki
	void ruch(Vector2u * granica);
	// przy kolizji z cegielka
	void odbijWPoziomie();
	void reset() override;
};

