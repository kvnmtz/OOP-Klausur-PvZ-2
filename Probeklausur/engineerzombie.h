#pragma once
#include "zombie.h"

class CEngineerZombie final : public CZombie
{
public:
	CEngineerZombie(CGarden& garden, int hp, CPosition pos, ELightSensitivity sensitivity, bool hasTools = false, bool isVegan = false);

	bool FireWeapon(CPosition targetPos) override;
};