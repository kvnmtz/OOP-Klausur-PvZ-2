#include "entity.h"

CEntity::CEntity(const EEntityType type, const CPosition pos, CGarden& garden) : Type(type), Position(pos), Garden(garden)
{
}

EEntityType CEntity::GetType() const
{
	return Type;
}

CPosition CEntity::GetPosition() const
{
	return Position;
}

void CEntity::SetPosition(const CPosition pos)
{
	this->Position = pos;
}

CGarden& CEntity::GetGarden() const
{
	return Garden;
}
