#include "Stone.h"

void Stones::Stone::Draw(Map & map) const
{
	map.Insert(loc, c);
}

void Stones::Stone::SetLocation(Location l)
{
	loc = l;
}

bool Stones::Stone::CollusionTest(Location l)
{
	return l == loc;
}

Stones::Stones(Location l)
{
	stones[0].SetLocation(l);
}

void Stones::Draw(Map& map) const
{
	for (int i = 0; i < num; i++)
	{
		stones[i].Draw(map);
	}
}

void Stones::Increase(Location l)
{
	stones[num].SetLocation(l);

	num++;
}

bool Stones::CollusionTest(Location l)
{
	bool col = false;

	for (int i = 0; i < num; i++)
	{
		if (stones[i].CollusionTest(l))
		{
			col = true;
		}
	}

	return col;
}
