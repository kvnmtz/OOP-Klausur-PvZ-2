#pragma once
#include "position.h"

class CGarden;

enum class EEntityType
{
	Plant,
	Zombie
};

class CEntity
{
	EEntityType Type;
	CPosition Position;
	CGarden& Garden;

public:
	CEntity(EEntityType type, CPosition pos, CGarden& garden);

	EEntityType GetType() const;

	CPosition GetPosition() const;

	void SetPosition(CPosition pos);

	CGarden& GetGarden() const;
};