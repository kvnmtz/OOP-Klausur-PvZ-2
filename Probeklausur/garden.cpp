// ReSharper disable CppMemberFunctionMayBeStatic
#include "garden.h"

#include <iostream>

CGarden::CGarden()
{
	/* Ich denke, dass das bei dem C++ Array nicht nötig ist, aber zur vollständigkeit halber hab ichs mal reingemacht */
	for (int i = 0; i < FieldsCount; ++i)
	{
		Fields[i] = nullptr;
	}
}

void CGarden::AddEntityToGarden(CEntity& entity)
{
	Fields[GetIndexFromPosition(entity.GetPosition())] = &entity;
}

int CGarden::GetIndexFromPosition(const CPosition position)
{
	return (position.Y - 1) * 7 + position.X - 1;
}

std::array<CEntity*, FieldsCount>& CGarden::GetFields()
{
	return Fields;
}

void CGarden::Render() const
{
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			const auto entity = Fields[i * 7 + j];
			if (!entity)
			{
				std::cout << "*";
			}
			else if (entity->GetType() == EEntityType::Plant)
			{
				std::cout << "P";
			}
			else
			{
				std::cout << "Z";
			}
		}
		std::cout << std::endl;
	}
}
