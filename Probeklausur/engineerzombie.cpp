#include "engineerzombie.h"

#include <iostream>

#include "random.hpp"

CEngineerZombie::CEngineerZombie(CGarden& garden, const int hp, const CPosition pos, const ELightSensitivity sensitivity, const bool hasTools, const bool isVegan)
	: CZombie(garden, hp, pos, sensitivity, hasTools, isVegan)
{
}

bool CEngineerZombie::FireWeapon(const CPosition targetPos)
{
	const auto distance = this->GetPosition().GetDistanceTo(targetPos);
	int chance;

	if (distance < 30.f)
	{
		chance = 80;
	}
	else
	{
		chance = 50;
	}

	if (this->GetHP() < 20)
	{
		chance -= 50;
	}

	if (Random::Success(chance))
	{
		std::cout << "Treffer!" << std::endl;
		return true;
	}

	std::cout << "Daneben..." << std::endl;
	return false;
}
