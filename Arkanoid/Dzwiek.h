#pragma once
#include <SFML/Audio.hpp>
using namespace sf;

class Dzwiek
{
	Sound odtwarzacz;
public:
	Dzwiek() {}
	Dzwiek(SoundBuffer * plik) : odtwarzacz(*plik) {};

	void odegraj_dzwiek()
	{
		odtwarzacz.play();
	}
};

