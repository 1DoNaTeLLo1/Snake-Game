#pragma once
#include "Colors.h"
#include "Map.h"
#include <random>

class Bait
{
	Location loc;
	Color c;

public:
	Bait();
	void Draw(Map& map) const;
	void Respawn(std::mt19937& rnd, std::uniform_int_distribution<int>& xDist, std::uniform_int_distribution<int>& yDist);
	Location GetLocation();
};