#pragma once
#include "Map.h"
#include "Colors.h"
#include "Bait.h"

class Snake
{
	struct Segment
	{
		Location loc;
		Color c;
	};

	static constexpr int c[4] = { 145, 200, 255, 200 };
	int color_counter = 0;

	static constexpr int max_tail_length = 100;
	Segment segment[max_tail_length];
	int len = 0;
	Location dir;
	bool waitTimer = false;

	void SetColor();

public:
	static constexpr Location right = { 1,0 };
	static constexpr Location left = { -1,0 };
	static constexpr Location up = { 0,-1 };
	static constexpr Location down = { 0,1 };

	Snake(Location loc, Location d);
	void Draw(Map& map);
	void Update();
	bool BorderTest(Map& map);
	void SetDirection(Location d);
	void Grow();
	void Follow();
	bool TailCollusion();
	bool IsEat(Bait& bait);
	Location GetLocation(int n) const;
};
