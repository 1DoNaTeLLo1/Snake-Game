#include "Bait.h"

Bait::Bait() :
	c(Colors::Yellow)
{
}

void Bait::Draw(Map& map) const
{
	map.Insert(loc, c);
}

void Bait::Respawn(std::mt19937& rnd, std::uniform_int_distribution<int>& xDist, std::uniform_int_distribution<int>& yDist)
{
	loc.x = xDist(rnd);
	loc.y = yDist(rnd);
}

Location Bait::GetLocation()
{
	return loc;
}
