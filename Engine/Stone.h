#pragma once
#include "Map.h"
#include "Colors.h"

class Stones
{
	class Stone
	{
		Location loc;
		static constexpr Color c = Colors::Gray;

	public:
		void Draw(Map& map) const;
		void SetLocation(Location l);
		bool CollusionTest(Location l);
	};

	static constexpr int max_stone = 100;
	Stone stones[max_stone];
	int num = 1;

public:
	void Draw(Map& map) const;
	void Increase(Location l);
	bool CollusionTest(Location l);
};
