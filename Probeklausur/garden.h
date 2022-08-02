// ReSharper disable CppClangTidyBugproneImplicitWideningOfMultiplicationResult
#pragma once
#include <array>

#include "entity.h"

constexpr int FieldsCount = 49;

class CGarden
{
	std::array<CEntity*, FieldsCount> Fields{};

public:
	CGarden();

	void AddEntityToGarden(CEntity& entity);

	int GetIndexFromPosition(CPosition position);

	std::array<CEntity*, FieldsCount>& GetFields();

	void Render() const;
};