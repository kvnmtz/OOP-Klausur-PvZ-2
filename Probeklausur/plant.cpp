#include "plant.h"

CPlant::CPlant(CGarden& garden, const CPosition pos) : CEntity(EEntityType::Plant, pos, garden)
{
}
