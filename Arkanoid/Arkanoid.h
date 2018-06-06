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
	Texture tlo_textura, cegla_textura, pilka_textura, paletka_tekstura;
	Sprite tlo;
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
		stworz_okno();
	};

private:
	void stworz_cegly()
	{
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
		tlo_textura.loadFromFile("images/background.jpg");
		tlo.setTexture(tlo_textura);
	}

	void stworz_paletke()
	{
		paletka_tekstura.loadFromFile("images/paddle.png");
		paletka = Paletka(&paletka_tekstura, Vector2f(300, 440));
	}

	void stworz_pilke(float szybkosc)
	{
	pilka_textura.loadFromFile("images/ball.png");
		pilka = Pilka(&pilka_textura,Vector2f(300,300),10);
	}

	void stworz_okno()
	{
		RenderWindow okno(VideoMode(520, 450), "Arkanoid!");

		// wykonuj dopoki okno jest otwarte
		while (okno.isOpen())
		{
			Event event;

			while (okno.pollEvent(event))
			{
				// gdy uzytkownik nacisnie zamkniecie okna to je zamknij
				if (event.type == Event::Closed)
					okno.close();
			}

			okno.clear(); // odswiezamy ekran

			// rysuj obiekty
			//for (size_t i = 0; i < cegiel_w_rzedzie*cegiel_w_kolumnie; i++)
			//	okno.draw(lista_cegiel[i]);


			//okno.draw(paletka);
			//okno.draw(pilka);
			okno.draw(tlo);
			okno.display();
		}
	}

	void czas_rozgrywki()
	{
	}

};

