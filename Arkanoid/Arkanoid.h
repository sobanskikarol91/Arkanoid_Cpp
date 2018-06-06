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
	Vector2i ile_cegiel;// ilosc cegiel w wierszach i kolumnach
	vector<Cegla> lista_cegiel;
	Paletka paletka;
	Pilka pilka;	

public:
	Arkanoid() {}

	// odstep_cegiel to odstep miedzy ceglami w kolumnie i wierszu
	Arkanoid(Vector2i ile_cegiel, Vector2f odstep_cegiel, float szybkosc) : ile_cegiel(ile_cegiel)
	{
		stworz_pilke(szybkosc);
		stworz_tlo();
		stworz_paletke();
		stworz_cegly(odstep_cegiel);
		stworz_okno();
	};

private:
	void stworz_cegly(Vector2f odstep)
	{
		cegla_textura.loadFromFile("images/block01.png");

		Vector2u wielkosc_tekstury = cegla_textura.getSize();
		// tworzymy cegly w rzedach i kolumnach
		for (size_t y = 0; y < ile_cegiel.y; y++)
		{
			for (size_t x = 0; x < ile_cegiel.x; x++)
			{
				// dodajemy do listy cegle ustawiajac jej teksture i pozycje i odstep miedzy ceglami

				Vector2f pozycja = Vector2f((odstep.x+ wielkosc_tekstury.x)*x, (wielkosc_tekstury.y + odstep.y)*y);

				lista_cegiel.push_back(Cegla(&cegla_textura, pozycja));
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

			// najpierw rysujemy tlo aby bylo z tylu
			okno.draw(tlo);

			// rysuj cegly
			for (size_t i = 0; i < ile_cegiel.x*ile_cegiel.y; i++)
				okno.draw(lista_cegiel[i]);

			okno.draw(paletka);
			okno.draw(pilka);
			okno.display();
		}
	}

	void czas_rozgrywki()
	{
	}

};

