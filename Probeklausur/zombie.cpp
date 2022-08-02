#include "zombie.h"

#include "garden.h"
#include "plant.h"
#include "toolfacet.h"
#include "veganfacet.h"

CZombie::CZombie(CGarden& garden, const int hp, const CPosition pos, const ELightSensitivity sensitivity, const bool hasTools, const bool isVegan)
	: CEntity(EEntityType::Zombie, pos, garden), HealthPoints(hp), Sensitivity(sensitivity)
{
	if (hasTools)
	{
		ToolFacet = new CToolFacet();
	}

	if (isVegan)
	{
		VeganFacet = new CVeganFacet();
	}
}

CZombie::~CZombie()
{
	delete ToolFacet;
	delete VeganFacet;
}

int CZombie::GetHP() const
{
	return HealthPoints;
}

ELightSensitivity CZombie::GetLightSensitivity() const
{
	return Sensitivity;
}

void CZombie::SetHP(const int hp)
{
	HealthPoints = hp;
}

CPlant* CZombie::SearchNearestPlant() const
{
	const int x = this->GetPosition().X;
	const int y = this->GetPosition().Y;
	for (int i = 1; i < 7; ++i)
	{
		int startX = x - i;
		int startY = y - i;
		int endX = x + i;
		int endY = y + i;
		if (startX < 1)
			startX = 1;
		if (endX > 7)
			endX = 7;
		if (startY < 1)
			startY = 1;
		if (endY > 7)
			endY = 7;
		for (int j = startX; j <= endX; ++j)
		{
			for (int k = startY; k <= endY; ++k)
			{
				if (startY < 1 || endY > 7)
					continue;
				const int index = GetGarden().GetIndexFromPosition(CPosition(j, k));
				const auto entity = GetGarden().GetFields()[index];
				if (!entity)
					continue;
				if (entity->GetType() != EEntityType::Plant)
					continue;
				return (CPlant*)entity;
			}
		}
	}
	return nullptr;
}
