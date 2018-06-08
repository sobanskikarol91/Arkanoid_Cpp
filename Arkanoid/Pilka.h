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
	Pilka() {}
	Pilka(Texture * tekstura, Vector2f pozycja, Vector2f predkosc)
		:Obrazek(tekstura), predkosc(predkosc), startowa_pozycja(pozycja), startowa_predkosc(predkosc)
	{
		sprite.setPosition(pozycja);
	};

	// poruszanie sie pilki
	void ruch(Vector2u * granica)
	{
		// okreslamy nowe polozenie
		Vector2f nowe_polozenie = sprite.getPosition() + predkosc;

		//  nowe_polozenie.x + sprite.getGlobalBounds().width - bierzemy pod uwage dolny prawy rog sprite
		if (nowe_polozenie.x < 0 || nowe_polozenie.x + sprite.getGlobalBounds().width > granica->x)
		{
			nowe_polozenie.x < 0 ? nowe_polozenie.x = 0 : nowe_polozenie.x = granica->x - sprite.getGlobalBounds().width;

			predkosc.x = -predkosc.x;

		}
		else if (nowe_polozenie.y  < 0 || nowe_polozenie.y + sprite.getGlobalBounds().height> granica->y)
		{
			// jak mniejsze od zera to ustaw na zero. jak wieksze od granicy to ustaw granice jako pozycje biorac pod uwage wielksoc sprite
			nowe_polozenie.y < 0 ? nowe_polozenie.y = 0 : nowe_polozenie.y = granica->y - sprite.getGlobalBounds().height;

			predkosc.y = -predkosc.y;
		}

		// aktualizujemy nowe polozenie ktore moglo zostac zmienione w ifach
		sprite.setPosition(nowe_polozenie);

	}

	// przy kolizji z cegielka
	void odbijWPoziomie()
	{
		predkosc.y *= -1;
	}

	void reset() override
	{
		predkosc = startowa_predkosc;
		sprite.setPosition(startowa_pozycja);
	}
};

