#pragma once

class CPosition
{
public:
	int X, Y;

	CPosition(int x, int y);

	float GetDistanceTo(const CPosition& other) const;
};