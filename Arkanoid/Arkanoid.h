#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cegla.h"
#include "Pilka.h"
#include "Paletka.h"
using namespace std;
using namespace sf;

class Arkanoid
{
	Texture tlo_tex, paletka_tex, cegla_tex, tlo_tex, pilka_tex;
	int cegiel_w_rzedzie, cegiel_w_kolumnie; // ilosc cegiel w wierszach i kolumnach
	vector<Cegla> lista_cegiel;
	Paletka paletka;
	Pilka pilka;	

public:
	Arkanoid() {}
	Arkanoid(int rzad_cegiel, int kolumna_cegiel, float szybkosc) : cegiel_w_rzedzie(rzad_cegiel), cegiel_w_kolumnie(kolumna_cegiel)
	{
		stworz_pilke(szybkosc);
		stworz_tlo();
		stworz_paletke();
		stworz_cegly();
	};

	void stworz_cegly()
	{
		Texture cegla_textura;
		cegla_textura.loadFromFile("images/block01.png");

		// tworzymy cegly w rzedach i kolumnach
		for (size_t r = 0; r < cegiel_w_rzedzie; r++)
		{
			for (size_t c = 0; c < cegiel_w_kolumnie; c++)
			{
				// dodajemy do listy cegle ustawiajac jej teksture
				lista_cegiel.push_back(Cegla(&cegla_textura, Vector2f(cegiel_w_rzedzie, cegiel_w_kolumnie)));
			}
		}
	}

	void stworz_tlo()
	{
		tlo_tex.loadFromFile("images/background.jpg");
	}

	void stworz_paletke()
	{
		paletka_tex.loadFromFile("images/paddle.png");
		paletka = Paletka(&paletka_tex, Vector2f(300, 440));
	}

	void stworz_pilke(float szybkosc)
	{
		pilka_tex.loadFromFile("images/ball.png");
		pilka = Pilka(szybkosc);
	}

	void utworz_okno()
	{
		RenderWindow okno(VideoMode(520, 450), "Arkanoid!");

		// wykonuj dopki uzytkownik nie zamknie okna
		while (okno.isOpen())
		{

		}
	}

	void czas_rozgrywki()
	{

	}
};

