#pragma once
#include "entity.h"
#include "position.h"

class CPlant : public CEntity
{
public:
	CPlant(CGarden& garden, CPosition pos);
};
