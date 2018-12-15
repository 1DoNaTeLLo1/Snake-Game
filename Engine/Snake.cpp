#include "Snake.h"

void Snake::SetColor()
{
	segment[len].c.SetG(c[len % 4]);
	segment[len].c.SetR(0);
	segment[len].c.SetR(0);
}

Snake::Snake(Location loc, Location d) :
	dir(d)
{
	segment[0].loc = { 10,10 };
	segment[0].c = headColor;
}

void Snake::Draw(Map& map)
{
	for (int i = 0; i <= len; i++)
	{
		map.Insert(segment[i].loc, segment[i].c);
	}
}

void Snake::Update()
{
	Follow();
	segment[0].loc += dir;
	waitTimer = false;
}

bool Snake::BorderTest(Map& map)
{
	return (segment[0].loc.x < 0 ||
		segment[0].loc.x >= map.GetWidth() ||
		segment[0].loc.y < 0 ||
		segment[0].loc.y >= map.GetHeight());
}

void Snake::SetDirection(Location d)
{
	if (!waitTimer)
	{
		if ((d == right && !(dir == left)) ||
			(d == left && !(dir == right)) ||
			(d == up && !(dir == down)) ||
			(d == down && !(dir == up)))
		{
			dir = d;
			waitTimer = true;
		}
	}
}

void Snake::Grow()
{
	len++;
	segment[len].loc = segment[len - 1].loc;
	SetColor();
}

void Snake::Follow()
{
	for (int i = len; i > 0; i--)
	{
		segment[i].loc = segment[i - 1].loc;
	}
}

bool Snake::TailCollusion()
{
	for (int i = 1; i <= len; i++)
	{
		if (segment[i].loc == segment[0].loc)
		{
			return true;
		}
	}

	return false;
}

bool Snake::IsEat(Bait & bait)
{
	return bait.GetLocation() == segment[0].loc;
}

Location Snake::GetLocation(int n) const
{
	return segment[n].loc;
}
